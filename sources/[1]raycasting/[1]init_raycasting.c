#include "../../includes/cub3D_struct.h"

static void	ft_initialize_player(t_cub3D *data, t_rc *rc)
{
	rc->player.i_coords.y = data->map.player._y;
	rc->player.i_coords.x = data->map.player._x;
	rc->player.d_coords.y = (double)rc->player.i_coords.y + 0.5;
	rc->player.d_coords.x = (double)rc->player.i_coords.x + 0.5;
	rc->player.direction = data->map.player._direction;
}

static void	ft_initialize_vectors(t_cub3D *data, t_rc *rc)
{
	rc->dir_vec.x = 1;
	rc->dir_vec.y = 0;
	if (rc->player.direction == 0)
		rc->dir_vec = rotate_2d_vector(rc->dir_vec, 270.0);
	else if (rc->player.direction == 1)
		rc->dir_vec = rotate_2d_vector(rc->dir_vec, 90.0);
	else if (rc->player.direction == 2)
		rc->dir_vec = rotate_2d_vector(rc->dir_vec, 0.0);
	else if (rc->player.direction == 3)
		rc->dir_vec = rotate_2d_vector(rc->dir_vec, 180.0);
	rc->scale_map = 75;
	rc->fov = ft_deg_to_rad((double)60);
	rc->ray_dist = (2 * tan(rc->fov / 2)) / data->win_x;
}

void	ft_initialize_door(t_cub3D *data)
{
	t_door	*door;

	door = &data->door;
	door->orientation_hit = -1;
	door->type_door = -1;
	door->status = NULL;
	door->timer = NULL;
	door->initial_dda.x = -1;
	door->initial_dda.y = -1;
	door->next_dda.x = -1;
	door->next_dda.y = -1;
}

void	ft_initialize_raycasting(t_cub3D *data)
{
	t_rc	*rc;

	rc = &data->rc;
	rc->doors = 0;
	ft_initialize_player(data, rc);
	ft_initialize_vectors(data, rc);
	ft_initialize_door(data);
}
