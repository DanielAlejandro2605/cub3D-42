/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:21:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/21 17:01:43 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_init_img(t_cub3D *data)
{
	t_image	*img;

	img = &data->img;
	img->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	if (img->img == NULL)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
									&img->line_len, &img->endian);
	img->offset_win_x = 0;
	img->offset_win_y = 0;
	return (0);
}

int	ft_exit(t_cub3D *data)
{
	int	i;

	i = 0;
	while (i < 8 && data && data->wall_textures[i].img)
		mlx_destroy_image(data->mlx, data->wall_textures[i++].img);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->ident_coord)
		ft_lstclear(&data->ident_coord, &ft_free_coord);
	if (data->ident_fc)
		ft_lstclear(&data->ident_fc, &ft_free_fc);
	ft_free_map(&data->map);
	exit(0);
}

int	setup_mlx_env(t_cub3D *data)
{
	int	i;

	data->win_x = 1200;
	data->win_y = 800;
	data->mid_x = data->win_x / 2;
	data->mid_y = data->win_y / 2;
	data->mlx = mlx_init();
	ft_bzero(&data->events, sizeof(t_event));
	if (data->mlx == NULL)
	{
		ft_free_map(&data->map);
		return (1);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->win_x, data->win_y, \
	"cub3D");
	if (data->mlx_win == NULL)
		return (free(data->mlx), 1);
	if (ft_init_img(data))
		return (free(data->mlx), free(data->mlx_win), 1);
	i = 0;
	while (i < 8)
		data->wall_textures[i++] = (t_tex){NULL, NULL, 0, 0, 0, 0, 0};
	return (0);
}
