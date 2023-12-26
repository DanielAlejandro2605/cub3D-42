/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [4]mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:40 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 23:56:42 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_minimap(t_cub3D *data, t_vec2D *first_pixel, t_vec2D *limits)
{
	first_pixel->x = data->rc.player.d_coords.x - 2.0;
	first_pixel->y = data->rc.player.d_coords.y - 2.0;
	limits->x = first_pixel->x + (2.0 * 2);
	limits->y = first_pixel->y + (2.0 * 2);
}

static void	draw_case(t_cub3D *data, int i, int j, int type_elem)
{
	if (type_elem == 1)
		draw_square(data, i * data->map_s, j * data->map_s, 4);
	else if (type_elem == 2)
		draw_square(data, i * data->map_s, j * data->map_s, 5);
	else if (type_elem == 3)
		draw_port_hori(data, i * data->map_s, j * data->map_s, data->map_s);
	else if (type_elem == 4)
		draw_port_vertical(data, i * data->map_s, j * data->map_s, data->map_s);
}

void	draw_square(t_cub3D *data, int y, int x, int obj)
{
	int	pixel_step_y;
	int	pixel_step_x;
	int	color;

	my_mlx_pixel_put(data, (t_point){x + 0, y + 0, 0x000000});
	pixel_step_y = 1;
	while (pixel_step_y < data->map_s)
	{
		pixel_step_x = 1;
		while (pixel_step_x < data->map_s)
		{
			if (obj == 1)
				color = 0x000000FF;
			else if (obj == 4)
				color = 0xC0EB34FF;
			else if (obj == 5)
				color = 0xFF0000FF;
			else
				color = 0xFFFFFFFF;
			my_mlx_pixel_put(data, \
			(t_point){x + pixel_step_x, y + pixel_step_y, color});
			pixel_step_x++;
		}
		pixel_step_y++;
	}
}

static void	row_minimap(t_cub3D *data, int i, t_vec2D *fp, t_vec2D *limits)
{
	int	j;
	int	type_elem;

	j = 5;
	while (fp->x < limits->x)
	{
		if (fp->y < 0.0 || fp->x < 0.0
			|| fp->y >= data->map.max_h || fp->x >= data->map.max_w)
			draw_square(data, i * data->map_s, j * data->map_s, 4);
		else if (ft_abs_double(fp->x - data->rc.player.d_coords.x) < 0.01
			&& ft_abs_double(fp->y - data->rc.player.d_coords.y) < 0.01)
			draw_square(data, i * data->map_s, j * data->map_s, 1);
		else
		{
			type_elem = check_elem_map(data, (int)fp->y, (int)fp->x);
			draw_case(data, i, j, type_elem);
		}
		fp->x = fp->x + 0.1;
		j++;
	}
}

void	draw_minimap(t_cub3D *data)
{
	t_vec2D	first_pixel;
	t_vec2D	limits;
	int		i;

	init_minimap(data, &first_pixel, &limits);
	i = 5;
	while (first_pixel.y < limits.y)
	{
		first_pixel.x = data->rc.player.d_coords.x - 2.0;
		row_minimap(data, i, &first_pixel, &limits);
		first_pixel.y = first_pixel.y + 0.1;
		i++;
	}
}
