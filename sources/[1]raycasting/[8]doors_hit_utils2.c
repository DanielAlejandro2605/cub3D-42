/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]doors_hit_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:06 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:07 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	hit_vertical_opening(t_rc *rc, t_ray *ray, t_door *d, int dir)
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
		{
			ray->orientation_wall_hit = 6;
		}
	}
}

void	next_hit_closed(t_rc *rc, t_ray *ray, t_door *d, int dir)
{
	if (dir == VERTICAL)
	{
		equation_straight_line(rc, ray, d->next_dda.x, HORIZONTAL);
		if (ray->hit_point.y < d->initial_dda.y
			||ray->hit_point.y > d->initial_dda.y + 1.0)
		{
			equation_straight_line(rc, ray, d->next_dda.y, VERTICAL);
			ray->orientation_wall_hit = 6;
		}
		else
			ray->orientation_wall_hit = 5;
	}
	else if (dir == HORIZONTAL)
	{
		equation_straight_line(rc, ray, d->next_dda.y, VERTICAL);
		if (ray->hit_point.x < d->initial_dda.x
			|| ray->hit_point.x > (d->initial_dda.x + 1.0))
		{
			equation_straight_line(rc, ray, d->next_dda.x, HORIZONTAL);
			ray->orientation_wall_hit = 8;
		}
		else
			ray->orientation_wall_hit = 7;
	}
}

void	next_hit_open(t_rc *rc, t_ray *ray, t_door *d, int dir)
{
	if (dir == VERTICAL)
	{
		equation_straight_line(rc, ray, d->next_dda.y, VERTICAL);
		if ((ray->hit_point.x >= d->initial_dda.x)
			&& (ray->hit_point.x <= d->next_dda.x))
			ray->orientation_wall_hit = 6;
	}
	else if (dir == HORIZONTAL)
	{
		equation_straight_line(rc, ray, d->next_dda.x, HORIZONTAL);
		if ((ray->hit_point.y >= d->initial_dda.y)
			&& (ray->hit_point.y <= d->next_dda.y))
			ray->orientation_wall_hit = 8;
	}
}
