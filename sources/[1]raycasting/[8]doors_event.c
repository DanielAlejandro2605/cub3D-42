/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]doors_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:01 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:39:29 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

static void	check_hook_vertical(t_rc *rc, t_ray *ray, t_door *door)
{
	if (ray->is_facing_rigth)
	{
		if (rc->center_screen.x >= (door->initial_dda.x + 0.2)
			&& ray->hit_point.x == door->initial_dda.x)
			check_door_hook(rc, door);
	}
	else if (ray->is_facing_left)
	{
		if (rc->center_screen.x <= (door->initial_dda.x + 0.8)
			&& ray->hit_point.x == (door->initial_dda.x + 1.0))
			check_door_hook(rc, door);
	}
}

static void	check_dist_door(t_rc *rc, t_ray *ray, t_door *door)
{
	if (door->type_door == VERTICAL_DOOR)
	{
		check_hook_vertical(rc, ray, door);
	}
	else if (door->type_door == HORIZONTAL_DOOR)
	{
		if (ray->is_facing_up)
		{
			if (rc->center_screen.y <= (door->initial_dda.y + 0.8)
				&& ray->hit_point.y == (door->initial_dda.y + 1.0))
				check_door_hook(rc, door);
		}
		else if (ray->is_facing_down)
		{
			if (rc->center_screen.y >= (door->initial_dda.y + 0.2)
				&& ray->hit_point.y == (door->initial_dda.y))
				check_door_hook(rc, door);
		}
	}
}

void	lauch_door_ray(t_cub3D *data, t_rc *rc, t_ray *ray_door)
{
	initialize_ray(ray_door, rc->dir_vec, 1);
	get_quadrant(ray_door);
	wall_finder(data, ray_door, rc);
	if (data->door.status != NULL)
	{
		check_dist_door(rc, ray_door, &data->door);
		if ((*data->door.status) == OPENING)
		{
			while ((*data->door.timer) < 1.0)
			{
				lauch_rays(data, rc);
				(*data->door.timer) = (*data->door.timer) + 0.05;
			}
			(*data->door.status) = OPEN;
		}
		else if ((*data->door.status) == CLOSING)
		{
			while ((*data->door.timer) > 0.0)
			{
				lauch_rays(data, rc);
				(*data->door.timer) = (*data->door.timer) - 0.05;
			}
			(*data->door.status) = CLOSED;
		}
	}
}
