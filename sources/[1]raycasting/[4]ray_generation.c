#include "../../includes/cub3D_struct.h"

static void	initialize_ray(t_ray *ray, t_vec2D ray_vec, int doors)
{
	if (doors == 1)
		ray->ray_type = 1;
	else
		ray->ray_type = 2;
	ray->vec = ray_vec;
	ray->hit_point.x = -1;
	ray->hit_point.y = -1;
	ray->dist = -1;
	ray->idx_tex = -1;
	ray->xpercent = -1.0;
	ray->orientation_wall_hit = -1;
	ray->is_facing_down = 0;
	ray->is_facing_up = 0;
	ray->is_facing_rigth = 0;
	ray->is_facing_left = 0;
}

/*Texture*/
static void	get_tex_xpercent(t_ray *ray)
{
	if (ray->orientation_wall_hit >= 1 && ray->orientation_wall_hit <= 4)
		ray->idx_tex = ray->orientation_wall_hit - 1;
	else if (ray->orientation_wall_hit == 5 || ray->orientation_wall_hit == 7)
	{
		ray->idx_tex = 4;
	}
	else if (ray->orientation_wall_hit == 6 || ray->orientation_wall_hit == 8)
		ray->idx_tex = 5;
	if (ray->orientation_wall_hit == 1 || ray->orientation_wall_hit == 2
		|| ray->orientation_wall_hit == 6 || ray->orientation_wall_hit == 7)
		ray->xpercent = (ray->hit_point.x - (float)((int)ray->hit_point.x));
	else if (ray->orientation_wall_hit == 3 || ray->orientation_wall_hit == 4
		|| ray->orientation_wall_hit == 5 || ray->orientation_wall_hit == 8)
		ray->xpercent = (ray->hit_point.y - (float)((int)ray->hit_point.y));
}

static void	get_quadrant(t_ray *ray)
{
	if (!(ft_abs_double(ray->vec.y) < 0.00001))
	{
		if (ray->vec.y < 0)
		{
			ray->is_facing_up = 1;
		}
		else if (ray->vec.y > 0)
		{
			ray->is_facing_down = 1;
		}
	}
	if (!(ft_abs_double(ray->vec.x) < 0.00001))
	{
		if (ray->vec.x < 0)
		{
			ray->is_facing_left = 1;
		}
		else if (ray->vec.x > 0)
		{
			ray->is_facing_rigth = 1;
		}
	}
}

static void	cast_ray(t_cub3D *data, t_rc *rc, t_vec2D ray_vec, int i)
{
	t_ray		ray;
	t_vec2D		ray_screen;
	t_vec2D		player_screen;

	player_screen = rc->player.d_coords;
	initialize_ray(&ray, ray_vec, 0);
	get_quadrant(&ray);
	wall_finder(data, &ray, rc, i);
	get_tex_xpercent(&ray);
	ray_screen = add_2d_vec(player_screen, ray.hit_point);
	ray_screen = scalar_mult(ray.hit_point, rc->scale_map);
	player_screen = scalar_mult(player_screen, rc->scale_map);
	// draw_column(data, &ray, i);

	if (ray.orientation_wall_hit >= 1 && ray.orientation_wall_hit <= 4)
		ft_draw_line(data, player_screen, ray_screen, 0xA020F0);
	else if (ray.orientation_wall_hit >= 5 && ray.orientation_wall_hit <= 8)
		ft_draw_line(data, player_screen, ray_screen, 0x8B0000);
}

static void	lauch_rays(t_cub3D *data, t_rc *rc)
{
	t_vec2D	cur_pix_pos;
	t_vec2D	current_ray_dir;
	int		i;

	i = 0;
	while (i <= data->win_x)
	{
			// Scalar multi is the multiplication between a vector and scalar number
			// per_vec -> Vector perpendicular
			cur_pix_pos = scalar_mult(rc->per_vec, tan(rc->fov * 0.5) - (rc->ray_dist * i));
			// Addition between 2 vectors
			current_ray_dir = add_2d_vec(cur_pix_pos, rc->dir_vec);
			normalize_vector(&current_ray_dir);
			cast_ray(data, rc, current_ray_dir, i);
		i++;
	}
}

static void	check_door_hook(t_rc *rc, t_door *door)
{
	if (rc->doors)
	{
		if ((*door->status) == CLOSED)
		{
			(*door->status) = OPENING;
		}
		else if ((*door->status) == OPEN)
		{
			(*door->status) = CLOSING;
		}
	}
	rc->doors = 0;
}

static void	check_dist_door(t_rc *rc, t_ray *ray, t_door *door)
{
	if (door->type_door == VERTICAL_DOOR)
	{
		if (ray->is_facing_rigth)
		{
			if (rc->center_screen.x >= (door->initial_dda.x + 0.2) && ray->hit_point.x == door->initial_dda.x)
				check_door_hook(rc, door);
		}
		else if (ray->is_facing_left)
		{
			if (rc->center_screen.x <= (door->initial_dda.x + 0.8) && ray->hit_point.x == (door->initial_dda.x + 1.0))
				check_door_hook(rc, door);
		}
	}
	else if (door->type_door == HORIZONTAL_DOOR)
	{
		if (ray->is_facing_up)
		{
			if (rc->center_screen.y <= (door->initial_dda.y + 0.8) && ray->hit_point.y == (door->initial_dda.y + 1.0))
				check_door_hook(rc, door);
		}
		else if (ray->is_facing_down)
		{
			if (rc->center_screen.y >= (door->initial_dda.y + 0.2) && ray->hit_point.y == (door->initial_dda.y))
				check_door_hook(rc, door);
		}
	}
}

static void	lauch_door_ray(t_cub3D *data, t_rc *rc)
{
	t_ray		ray_door;
	int			i;

	initialize_ray(&ray_door, rc->dir_vec, 1);
	get_quadrant(&ray_door);
	wall_finder(data, &ray_door, rc, 0);
	if (data->door.status != NULL)
	{
		check_dist_door(rc, &ray_door, &data->door);
		if ((*data->door.status) == OPENING)
		{
			i = 0;
			while ((*data->door.timer) < 1.0)
			{
				lauch_rays(data, rc);
				usleep(100);
				(*data->door.timer) = (*data->door.timer) + 0.05;
				i++;
			}
			(*data->door.status) = OPEN;
		}
		else if ((*data->door.status) == CLOSING)
		{
			while ((*data->door.timer) > 0.0)
			{
				lauch_rays(data, rc);
				usleep(100);
				(*data->door.timer) = (*data->door.timer) - 0.05;
			}
			(*data->door.status) = CLOSED;
		}
	}
}

void    raycasting(t_cub3D *data)
{
    t_rc	*rc;

	rc = &data->rc;
	rc->per_vec = ft_get_perpendicular_vec(rc->dir_vec);
	rc->center_screen = add_2d_vec(rc->player.d_coords, rc->dir_vec);
	_raycasting(data);
	lauch_door_ray(data, rc);
	lauch_rays(data, rc);
	// draw_minimap(data);
}
