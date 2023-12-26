/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [3]hooks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:34 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:21:35 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_vec2D	check_step(t_cub3D *data, int map_elem, t_vec2D new_pos)
{
	int		door_state;

	if (map_elem == 1 || (map_elem == 32))
		return (data->rc.player.d_coords);
	else if (map_elem == 2 || map_elem == 3)
	{
		door_state = data->map.door_state_map[(int)new_pos.y][(int)new_pos.x];
		if (door_state == CLOSED)
			return (data->rc.player.d_coords);
		else if (door_state == OPEN)
			return (new_pos);
	}
	return (new_pos);
}

void	ft_rotate_dir_vec(t_cub3D *data, int rotation_direction)
{
	if (rotation_direction == 1)
	{
		data->rc.dir_vec = rotate_2d_vector(data->rc.dir_vec, -15.0);
	}
	else if (rotation_direction == 2)
	{
		data->rc.dir_vec = rotate_2d_vector(data->rc.dir_vec, 15.0);
	}
}

t_vec2D	move_for_back_ward(t_cub3D *data, int flag)
{
	t_vec2D	n_pos;
	int		square_value;

	if (flag == MOVE_FORWARD)
	{
		n_pos = scalar_mult(data->rc.dir_vec, 0.2);
		n_pos = add_2d_vec(data->rc.player.d_coords, n_pos);
	}
	else if (flag == MOVE_BACKWARD)
	{
		n_pos = scalar_mult(data->rc.dir_vec, -0.2);
		n_pos = add_2d_vec(data->rc.player.d_coords, n_pos);
	}
	square_value = data->map.map[(int)n_pos.y][(int)n_pos.x];
	return (check_step(data, square_value, n_pos));
}

t_vec2D	move_left_rigth(t_cub3D *data, int flag)
{
	t_vec2D	n_pos;
	int		square_value;

	if (flag == MOVE_LEFT)
	{
		n_pos = scalar_mult(data->rc.per_vec, 0.2);
		n_pos = add_2d_vec(data->rc.player.d_coords, n_pos);
	}
	else if (flag == MOVE_RIGTH)
	{
		n_pos = scalar_mult(data->rc.per_vec, -0.2);
		n_pos = add_2d_vec(data->rc.player.d_coords, n_pos);
	}
	square_value = data->map.map[(int)n_pos.y][(int)n_pos.x];
	return (check_step(data, square_value, n_pos));
}
