/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:09 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:21:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	ft_deg_to_rad(double angle)
{
	double	radians;

	radians = angle * (M_PI / 180);
	return (radians);
}

void	normalize_vector(t_vec2D *vector)
{
	double	length;

	length = sqrt(vector->x * vector->x + vector->y * vector->y);
	vector->x /= length;
	vector->y /= length;
}

double	ft_abs_double(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_diff_epsilon(double n1, double n2)
{
	if (ft_abs_double(n1 - n2) < 0.00001)
		return (1);
	return (0);
}

double	vec_cross_product(t_vec2D v1, t_vec2D v2)
{
	return (v1.x * v2.y - v1.y * v2.x);
}
