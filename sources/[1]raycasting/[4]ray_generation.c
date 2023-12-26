/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [4]ray_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:43 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:21:44 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	initialize_ray(t_ray *ray, t_vec2D ray_vec, int doors)
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

void	get_quadrant(t_ray *ray)
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

	initialize_ray(&ray, ray_vec, 0);
	get_quadrant(&ray);
	wall_finder(data, &ray, rc);
	get_tex_xpercent(&ray);
	draw_column(data, &ray, i);
}

void	lauch_rays(t_cub3D *data, t_rc *rc)
{
	t_vec2D	pix_pos;
	t_vec2D	current_ray_dir;
	int		i;

	i = 0;
	while (i <= data->win_x)
	{
		pix_pos = scalar_mult(rc->per_vec, \
		tan(rc->fov * 0.5) - (rc->ray_dist * i));
		current_ray_dir = add_2d_vec(pix_pos, rc->dir_vec);
		normalize_vector(&current_ray_dir);
		cast_ray(data, rc, current_ray_dir, i);
		i++;
	}
}
