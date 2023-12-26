/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]doors_hit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:04 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:05 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	hit_horizontal_opening(t_rc *rc, t_ray *ray, t_door *d, int dir)
{
	float	current_timer;

	current_timer = ((d->initial_dda.x + 1.0) - (*d->timer));
	equation_straight_line(rc, ray, d->next_dda.y, dir);
	if ((ray->hit_point.x >= d->initial_dda.x)
		&& (ray->hit_point.x <= current_timer))
		ray->orientation_wall_hit = 7;
	else
	{
		equation_straight_line(rc, ray, d->next_dda.x, HORIZONTAL);
		if ((ray->hit_point.y >= d->initial_dda.y)
			&& (ray->hit_point.y <= (d->initial_dda.y + 1.0)))
			ray->orientation_wall_hit = 8;
	}
}

static void	hit_vertical_closing(t_rc *rc, t_ray *ray, t_door *d, int dir)
{
	float	current_timer;

	current_timer = ((d->initial_dda.y + 1.0) - (*d->timer));
	equation_straight_line(rc, ray, d->next_dda.x, dir);
	if ((ray->hit_point.y >= d->initial_dda.y)
		&& (ray->hit_point.y <= current_timer))
		ray->orientation_wall_hit = 5;
	else
	{
		equation_straight_line(rc, ray, d->next_dda.y, VERTICAL);
		if ((ray->hit_point.x >= d->initial_dda.x)
			&& (ray->hit_point.x <= (d->initial_dda.x + 1.0)))
			ray->orientation_wall_hit = 6;
	}
}

static void	hit_horizontal_closing(t_rc *rc, t_ray *ray, t_door *d, int dir)
{
	float	current_timer;

	current_timer = ((d->initial_dda.x + 1.0) - (*d->timer));
	equation_straight_line(rc, ray, d->next_dda.y, dir);
	if ((ray->hit_point.x >= d->initial_dda.x)
		&& (ray->hit_point.x <= current_timer))
		ray->orientation_wall_hit = 7;
	else
	{
		equation_straight_line(rc, ray, d->next_dda.x, HORIZONTAL);
		if ((ray->hit_point.y >= d->initial_dda.y)
			&& (ray->hit_point.y <= (d->initial_dda.y + 1.0)))
			ray->orientation_wall_hit = 8;
	}
}

void	horizontal_door(t_cub3D *data, t_ray *ray, t_door *door)
{
	if ((*door->status) == CLOSED)
		next_hit_closed(&data->rc, ray, door, HORIZONTAL);
	else if ((*door->status) == OPEN)
		next_hit_open(&data->rc, ray, door, HORIZONTAL);
	else if ((*door->status) == OPENING)
		hit_horizontal_opening(&data->rc, ray, door, VERTICAL);
	else if ((*door->status) == CLOSING)
		hit_horizontal_closing(&data->rc, ray, door, HORIZONTAL);
}

void	vertical_door(t_cub3D *data, t_ray *ray, t_door *door)
{
	if ((*door->status) == CLOSED)
		next_hit_closed(&data->rc, ray, door, VERTICAL);
	else if ((*door->status) == OPEN)
		next_hit_open(&data->rc, ray, door, VERTICAL);
	else if ((*door->status) == OPENING)
		hit_vertical_opening(&data->rc, ray, door, HORIZONTAL);
	else if ((*door->status) == CLOSING)
		hit_vertical_closing(&data->rc, ray, door, HORIZONTAL);
}
