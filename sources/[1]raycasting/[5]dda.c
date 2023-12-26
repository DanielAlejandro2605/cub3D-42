/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5]dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:21:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	fuck_normi(t_ray *ray, t_vec2D *dda_corners, t_vec2D *curr_dda)
{
	dda_corners->y = curr_dda->y;
	if (ft_abs_double(ray->hit_point.y - dda_corners->y) < 0.00001)
	{
		if (ray->is_facing_rigth)
			ray->orientation_wall_hit = 5;
		else if (ray->is_facing_left)
			ray->orientation_wall_hit = 6;
	}
}

static void	corners(t_rc *rc, t_ray *ray, t_vec2D *curr_dda)
{
	t_vec2D	dda_corners;

	dda_corners.y = 0;
	dda_corners.x = 0;
	if (ray->is_facing_rigth)
		dda_corners.x = (curr_dda->x + 1);
	else if (ray->is_facing_left)
		dda_corners.x = (curr_dda->x);
	equation_straight_line(rc, ray, dda_corners.x, HORIZONTAL);
	if (ray->is_facing_up)
		fuck_normi(ray, &dda_corners, curr_dda);
	else if (ray->is_facing_down)
	{
		dda_corners.y = curr_dda->y + 1;
		if (ft_abs_double(ray->hit_point.y - dda_corners.y) < 0.00001)
		{
			if (ray->is_facing_rigth)
				ray->orientation_wall_hit = 7;
			else if (ray->is_facing_left)
				ray->orientation_wall_hit = 8;
		}
	}
}

static int	check_pos_player(t_cub3D *data, t_vec2D *curr_dda)
{
	int	pos_player;

	pos_player = data->map.map[(int)curr_dda->y][(int)curr_dda->x];
	if (pos_player == 2 || pos_player == 3)
		return (1);
	return (0);
}

static void	go_through_door(t_cub3D *data, t_ray *ray, t_vec2D pos_player)
{
	t_vec2D	d_c;
	int		door_type;

	door_type = data->map.map[(int)pos_player.y][(int)pos_player.x];
	d_c.y = (int)pos_player.y;
	d_c.x = (int)pos_player.x;
	if (door_type == VERTICAL_DOOR)
	{
		if (ray->is_facing_up || ray->is_facing_down)
		{
			if (ray->hit_point.x >= d_c.x && ray->hit_point.x <= (d_c.x + 1.0))
				ray->orientation_wall_hit = 6;
		}
	}
	else if (door_type == HORIZONTAL_DOOR)
	{
		if (ray->is_facing_rigth || ray->is_facing_left)
		{
			if (ray->hit_point.y >= d_c.y && ray->hit_point.y <= (d_c.y + 1.0))
				ray->orientation_wall_hit = 8;
		}
	}
}

void	wall_finder(t_cub3D *data, t_ray *ray, t_rc *rc)
{
	t_vec2D	curr_dda;
	t_vec2D	pos_player;
	int		hit;

	hit = 0;
	get_int_coords(&data->rc.player, &pos_player);
	curr_dda.y = pos_player.y;
	curr_dda.x = pos_player.x;
	while (!hit)
	{
		corners(rc, ray, &curr_dda);
		hit_xy_axis(rc, ray, &curr_dda);
		if (ray->orientation_wall_hit == 1)
			curr_dda.y = curr_dda.y - 1;
		if (ray->orientation_wall_hit == 2)
			curr_dda.y = curr_dda.y + 1;
		if (ray->orientation_wall_hit == 3)
			curr_dda.x = curr_dda.x + 1;
		if (ray->orientation_wall_hit == 4)
			curr_dda.x = curr_dda.x - 1;
		dda_corners(data->map.map, ray, &curr_dda, &hit);
		check_hit(data, ray, &curr_dda, &hit);
	}
	if (check_pos_player(data, &pos_player))
		go_through_door(data, ray, pos_player);
}
