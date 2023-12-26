#include "../../includes/cub3D_struct.h"

void	draw_square_player(t_cub3D *data, t_rc *rc, int scale_map)
{
	t_player	player;
	int			y;
	int			x;
	int			pix_step_y;
	int			pix_step_x;

	player = rc->player;
	y = (int)(player.d_coords.y * scale_map * 2.0);
	x = (int)(player.d_coords.x * scale_map * 2.0);
	pix_step_y = 0;
	while (pix_step_y < scale_map)
	{
		pix_step_x = 0;
		while (pix_step_x < scale_map)
		{
			my_mlx_pixel_put(data, (t_point){x + pix_step_x, \
			y + pix_step_y, 0x7C6965});
			pix_step_x++;
		}
		pix_step_y++;
	}
}

int	check_elem_map(t_cub3D *data, int y, int x)
{
	int	elem_map;

	elem_map = data->map.map[y][x];
	if (elem_map == 0 || elem_map == 32 || elem_map == 'N' || elem_map == 'S'
		|| elem_map == 'W' || elem_map == 'E')
		return (1);
	else if (elem_map == 1)
		return (2);
	else if (elem_map == HORIZONTAL_DOOR)
	{
		if (data->map.door_state_map[y][x] == OPEN)
			return (1);
		else if (data->map.door_state_map[y][x] == CLOSED)
			return (3);
	}
	else if (elem_map == VERTICAL_DOOR)
	{
		if (data->map.door_state_map[y][x] == OPEN)
			return (1);
		else if (data->map.door_state_map[y][x] == CLOSED)
			return (4);
	}
	return (0);
}

void	draw_port_vertical(t_cub3D *data, int y, int x, int square_size)
{
	int	pix_step_y;
	int	pix_step_x;

	pix_step_y = 0;
	while (pix_step_y < square_size)
	{
		pix_step_x = 0;
		while (pix_step_x < square_size)
		{
			if (pix_step_x == (square_size / 2))
			{
				my_mlx_pixel_put(data, (t_point){x + pix_step_x, \
				y + pix_step_y, 0xFFFFFF});
			}
			else
			{
				my_mlx_pixel_put(data, (t_point){x + pix_step_x, \
				y + pix_step_y, 0x7C6965});
			}
			pix_step_x++;
		}
		pix_step_y++;
	}
}

void	draw_port_hori(t_cub3D *data, int y, int x, int square_size)
{
	int	p_y;
	int	p_x;

	p_y = 0;
	while (p_y < square_size)
	{
		p_x = 0;
		if (p_y == (square_size / 2))
		{
			while (p_x < square_size)
			{
				my_mlx_pixel_put(data, (t_point){x + p_x, y + p_y, 0xFFFFFF});
				p_x++;
			}
		}
		else
		{
			while (p_x < square_size)
			{
				my_mlx_pixel_put(data, (t_point){x + p_x, y + p_y, 0x7C6965});
				p_x++;
			}
		}
		p_y++;
	}
}