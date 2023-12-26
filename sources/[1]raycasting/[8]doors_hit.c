/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]doors_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:08 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:09 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_door(t_cub3D *data, t_door *d, t_vec2D *curr_dda)
{
	d->orientation_hit = -1;
	d->type_door = data->map.map[(int)curr_dda->y][(int)curr_dda->x];
	d->status = &data->map.door_state_map[(int)curr_dda->y][(int)curr_dda->x];
	d->timer = &data->map.timer_map[(int)curr_dda->y][(int)curr_dda->x];
	d->initial_dda.x = curr_dda->x;
	d->initial_dda.y = curr_dda->y;
	d->next_dda.x = -1;
	d->next_dda.y = -1;
}

static int	init_new_points_horizontal(t_ray *ray, t_door *d)
{
	if ((*d->status) == OPEN)
	{
		if (ray->is_facing_up || ray->is_facing_down)
		{
			d->next_dda.y = d->initial_dda.y + 1.0;
			if (!ray->is_facing_rigth && !ray->is_facing_left)
			{
				ray->orientation_wall_hit = -1;
				return (1);
			}
		}
	}
	else
		d->next_dda.y = d->initial_dda.y + 0.5;
	if (ray->is_facing_left)
		d->next_dda.x = d->initial_dda.x;
	else if (ray->is_facing_rigth)
		d->next_dda.x = d->initial_dda.x + 1.0;
	return (0);
}

static int	init_new_points_vertical(t_ray *ray, t_door *door)
{
	if ((*door->status) == OPEN)
	{
		if (ray->is_facing_rigth || ray->is_facing_left)
		{
			door->next_dda.x = door->initial_dda.x + 1.0;
			if (!ray->is_facing_up && !ray->is_facing_down)
			{
				ray->orientation_wall_hit = -1;
				return (1);
			}
		}
	}
	else
		door->next_dda.x = door->initial_dda.x + 0.5;
	if (ray->is_facing_up)
		door->next_dda.y = door->initial_dda.y;
	else if (ray->is_facing_down)
		door->next_dda.y = door->initial_dda.y + 1.0;
	return (0);
}

static int	get_next_hit(t_cub3D *data, t_ray *ray, t_door *door)
{
	int		hit_door;

	hit_door = -1;
	ray->orientation_wall_hit = -1;
	if (door->type_door == HORIZONTAL_DOOR)
	{
		if (!init_new_points_horizontal(ray, door))
		{
			horizontal_door(data, ray, door);
		}
	}
	else if (door->type_door == VERTICAL_DOOR)
	{
		if (!init_new_points_vertical(ray, door))
			vertical_door(data, ray, door);
	}
	if (ray->orientation_wall_hit != -1)
		hit_door = 1;
	else
		hit_door = 0;
	return (hit_door);
}

int	handle_door_hit(t_cub3D *data, t_ray *ray, t_vec2D *curr_dda)
{
	int		value;

	if (ray->ray_type != 1)
	{
		init_door(data, &data->door, curr_dda);
		value = get_next_hit(data, ray, &data->door);
		return (value);
	}
	return (1);
}
