/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:21:16 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_vec2D	rotate_2d_vector(t_vec2D vec, int angle)
{
	t_vec2D	rotate_vec;
	double	angle_radians;

	angle_radians = ft_deg_to_rad((double)angle);
	rotate_vec.x = (vec.x * cos(angle_radians)) - (vec.y * sin(angle_radians));
	rotate_vec.y = (vec.x * sin(angle_radians)) + (vec.y * cos(angle_radians));
	return (rotate_vec);
}

static void	get_perpendicular_vec(t_vec2D vec, t_vec2D *res_perpendicular_vec)
{
	if (vec.x > 0)
	{
		res_perpendicular_vec->x = 0;
		res_perpendicular_vec->y = -1;
	}
	else if (vec.x < 0)
	{
		res_perpendicular_vec->x = 0;
		res_perpendicular_vec->y = 1;
	}
}

t_vec2D	ft_get_perpendicular_vec(t_vec2D vec)
{
	t_vec2D	res_perpendicular_vec;
	double	norm;

	res_perpendicular_vec.x = 0;
	res_perpendicular_vec.y = 0;
	if (vec.y != 0)
	{
		if (vec.y < 0)
		{
			norm = sqrt(1 + ((vec.x * vec.x) / (vec.y * vec.y)));
			res_perpendicular_vec.x = -1 / norm;
			res_perpendicular_vec.y = (vec.x / vec.y) / norm;
		}
		else if (vec.y > 0)
		{
			norm = sqrt(1 + ((vec.x * vec.x) / (vec.y * vec.y)));
			res_perpendicular_vec.x = 1 / norm;
			res_perpendicular_vec.y = -(vec.x / vec.y) / norm;
		}
	}
	else
	{
		get_perpendicular_vec(vec, &res_perpendicular_vec);
	}
	return (res_perpendicular_vec);
}
