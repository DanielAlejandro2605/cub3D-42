/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [3]hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:36 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/14 00:00:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	exec_hook(t_cub3D *data)
{
	if (data->events.move_left)
		data->rc.player.d_coords = move_left_rigth(data, MOVE_LEFT);
	if (data->events.move_rigth)
		data->rc.player.d_coords = move_left_rigth(data, MOVE_RIGTH);
	if (data->events.move_forward)
		data->rc.player.d_coords = move_for_back_ward(data, MOVE_FORWARD);
	if (data->events.move_backward)
		data->rc.player.d_coords = move_for_back_ward(data, MOVE_BACKWARD);
	if (data->events.rotate_left)
		ft_rotate_dir_vec(data, 1);
	if (data->events.rotate_rigth)
		ft_rotate_dir_vec(data, 2);
	render(data);
	return (0);
}

static int	desactive_hook(int key_code, t_cub3D *data)
{
	if (key_code == 32)
		data->rc.doors = 0;
	if (key_code == MOVE_LEFT)
		data->events.move_left = 0;
	else if (key_code == MOVE_RIGTH)
		data->events.move_rigth = 0;
	else if (key_code == MOVE_FORWARD)
		data->events.move_forward = 0;
	else if (key_code == MOVE_BACKWARD)
		data->events.move_backward = 0;
	else if (key_code == ROTATE_LEFT)
		data->events.rotate_left = 0;
	else if (key_code == ROTATE_RIGTH)
		data->events.rotate_rigth = 0;
	return (0);
}

static int	active_hook(int key_code, t_cub3D *data)
{
	if (key_code == 32)
		data->rc.doors = 1;
	if (key_code == MOVE_LEFT)
		data->events.move_left = 1;
	else if (key_code == MOVE_RIGTH)
		data->events.move_rigth = 1;
	else if (key_code == MOVE_FORWARD)
		data->events.move_forward = 1;
	else if (key_code == MOVE_BACKWARD)
		data->events.move_backward = 1;
	else if (key_code == ROTATE_LEFT)
		data->events.rotate_left = 1;
	else if (key_code == ROTATE_RIGTH)
		data->events.rotate_rigth = 1;
	else if (key_code == ESCAPE)
		return (ft_exit(data), 0);
	exec_hook(data);
	return (0);
}

void	setup_controls_hooks(t_cub3D *data)
{
	mlx_hook(data->mlx_win, 2, (1L << 0), active_hook, data);
	mlx_hook(data->mlx_win, 3, (1L << 1), desactive_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
}
