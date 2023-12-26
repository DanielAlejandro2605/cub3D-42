#include "../../includes/cub3D_struct.h"

static void	cor_up_left(int **map, t_ray *ray, t_vec2D *current_dda, int *hit)
{
	if (map[(int)current_dda->y - 1][(int)current_dda->x] == 1)
	{
		current_dda->y = current_dda->y - 1;
		ray->orientation_wall_hit = 1;
		*hit = 1;
	}
	else if (map[(int)current_dda->y][(int)current_dda->x - 1] == 1)
	{
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = 4;
		*hit = 1;
	}
	else if (map[(int)current_dda->y - 1][(int)current_dda->x - 1] == 1)
	{
		current_dda->y = current_dda->y - 1;
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = 1;
		*hit = 1;
	}
	else
	{
		current_dda->y = current_dda->y - 1;
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = -1;
	}
}

static void	cor_up_rigth(int **map, t_ray *ray, t_vec2D *current_dda, int *hit)
{
	if (map[(int)current_dda->y - 1][(int)current_dda->x] == 1)
	{
		current_dda->y = current_dda->y - 1;
		ray->orientation_wall_hit = 1;
		*hit = 1;
	}
	else if (map[(int)current_dda->y][(int)current_dda->x + 1] == 1)
	{
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = 3;
		*hit = 1;
	}
	else if (map[(int)current_dda->y - 1][(int)current_dda->x + 1] == 1)
	{
		current_dda->y = current_dda->y - 1;
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = 3;
		*hit = 1;
	}
	else
	{
		current_dda->y = current_dda->y - 1;
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = -1;
	}
}

static void	cor_down_rigth(int **m, t_ray *ray, t_vec2D *current_dda, int *hit)
{
	if (m[(int)current_dda->y + 1][(int)current_dda->x] == 1)
	{
		current_dda->y = current_dda->y + 1;
		ray->orientation_wall_hit = 2;
		*hit = 1;
	}
	else if (m[(int)current_dda->y][(int)current_dda->x + 1] == 1)
	{
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = 3;
		*hit = 1;
	}
	else if (m[(int)current_dda->y + 1][(int)current_dda->x + 1] == 1)
	{
		current_dda->y = current_dda->y + 1;
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = 2;
		*hit = 1;
	}
	else
	{
		current_dda->y = current_dda->y + 1;
		current_dda->x = current_dda->x + 1;
		ray->orientation_wall_hit = -1;
	}
}

static void	cor_down_left(int **map, t_ray *ray, t_vec2D *current_dda, int *hit)
{
	if (map[(int)current_dda->y + 1][(int)current_dda->x] == 1)
	{
		current_dda->y = current_dda->y + 1;
		ray->orientation_wall_hit = 2;
		*hit = 1;
	}
	else if (map[(int)current_dda->y][(int)current_dda->x - 1] == 1)
	{
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = 4;
		*hit = 1;
	}
	else if (map[(int)current_dda->y + 1][(int)current_dda->x - 1] == 1)
	{
		current_dda->y = current_dda->y + 1;
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = 4;
		*hit = 1;
	}
	else
	{
		current_dda->y = current_dda->y + 1;
		current_dda->x = current_dda->x - 1;
		ray->orientation_wall_hit = -1;
	}
}

void	dda_corners(int **map, t_ray *ray, t_vec2D *current_dda, int *hit)
{
	if (ray->orientation_wall_hit == 5)
	{
		cor_up_rigth(map, ray, current_dda, hit);
	}
	if (ray->orientation_wall_hit == 6)
	{
		cor_up_left(map, ray, current_dda, hit);
	}
	if (ray->orientation_wall_hit == 7)
	{
		cor_down_rigth(map, ray, current_dda, hit);
	}
	if (ray->orientation_wall_hit == 8)
	{
		cor_down_left(map, ray, current_dda, hit);
	}
}
