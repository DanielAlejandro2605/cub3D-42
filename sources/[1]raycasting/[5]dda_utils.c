#include "../../includes/cub3D_struct.h"

void	get_int_coords(t_player *player, t_vec2D *curr_dda)
{
	double		integer_value;
	double		double_value;

	double_value = modf(player->d_coords.x, &integer_value);
	player->i_coords.x = (int)integer_value;
	double_value = modf(player->d_coords.y, &integer_value);
	player->i_coords.y = (int)integer_value;
	(void)double_value;
	curr_dda->x = player->i_coords.x;
	curr_dda->y = player->i_coords.y;
}

void	equation_straight_line(t_rc *rc, t_ray *ray, double curr_dda, int dir)
{
	if (dir == VERTICAL)
	{
		ray->dist = (curr_dda - rc->player.d_coords.y) / ray->vec.y;
		ray->hit_point.x = rc->player.d_coords.x + (ray->dist * ray->vec.x);
		ray->hit_point.y = curr_dda;
	}
	else if (dir == HORIZONTAL)
	{
		ray->dist = (curr_dda - rc->player.d_coords.x) / ray->vec.x;
		ray->hit_point.y = rc->player.d_coords.y + (ray->dist * ray->vec.y);
		ray->hit_point.x = curr_dda;
	}
}

void	check_hit(t_cub3D *data, t_ray *ray, t_vec2D *curr_dda, int *hit)
{
	int		map_elem;

	map_elem = -1;
	if ((int)curr_dda->y >= 0 && (int)curr_dda->y < data->map.max_h
		&& (int)curr_dda->x >= 0 && (int)curr_dda->x < data->map.max_w)
	{
		map_elem = data->map.map[(int)curr_dda->y][(int)curr_dda->x];
		if (map_elem == 1)
		{
			*hit = 1;
		}
		else if (map_elem >= 2 && map_elem <= 3)
		{
			*hit = handle_door_hit(data, ray, curr_dda);
		}
		else
			ray->orientation_wall_hit = -1;
	}
}

void	horizontal_hit(t_ray *ray, t_vec2D *curr_dda, int ray_orientation)
{
	if (ray->hit_point.y > curr_dda->y && ray->hit_point.y < (curr_dda->y + 1))
	{
		ray->orientation_wall_hit = ray_orientation;
	}
	else if ((ft_abs_double(ray->hit_point.y - (curr_dda->y)) < 0.000001)
		&& ray->hit_point.y < (curr_dda->y + 1))
	{
		ray->orientation_wall_hit = ray_orientation;
	}
}

void	hit_xy_axis(t_cub3D *data, t_rc *rc, t_ray *ray, t_vec2D *c_dda)
{
	if (ray->is_facing_left == 1 && ray->orientation_wall_hit == -1)
	{
		horizontal_hit(ray, c_dda, 4);
	}
	else if (ray->is_facing_rigth == 1 && ray->orientation_wall_hit == -1)
	{
		horizontal_hit(ray, c_dda, 3);
	}
	if (ray->is_facing_up == 1 && ray->orientation_wall_hit == -1)
	{
		equation_straight_line(rc, ray, c_dda->y, VERTICAL);
		if (ray->hit_point.x > c_dda->x && ray->hit_point.x < (c_dda->x + 1))
			ray->orientation_wall_hit = 1;
	}
	else if (ray->is_facing_down == 1 && ray->orientation_wall_hit == -1)
	{
		equation_straight_line(rc, ray, c_dda->y + 1, VERTICAL);
		if (ray->hit_point.x > c_dda->x && ray->hit_point.x < (c_dda->x + 1))
			ray->orientation_wall_hit = 2;
	}
}
