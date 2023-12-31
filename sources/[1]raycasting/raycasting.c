/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:15 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 18:18:13 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static unsigned int	find_color(t_list *ident_fc, unsigned int t)
{
	while (ident_fc && ((t_fc *)(ident_fc->content)) && \
	((t_fc *)(ident_fc->content))->id != t)
		ident_fc = ident_fc->next;
	return (((t_fc *)(ident_fc->content))->r << 16 \
	| ((t_fc *)(ident_fc->content))->g << 8 \
	| ((t_fc *)(ident_fc->content))->b);
}

static t_tex	get_tex_path(t_cub3D *data, char *path)
{
	t_tex	texture;

	texture = (t_tex){NULL, NULL, 0, 0, 0, 0, 0};
	texture.img = mlx_xpm_file_to_image(data->mlx, path, \
	&texture.img_width, &texture.img_height);
	if (texture.img == NULL)
		return (printf(MLX_ERROR), ft_exit(data), texture);
	texture.addr = mlx_get_data_addr(texture.img, \
	&texture.bpp, &texture.line_len, &texture.endian);
	if (texture.addr == NULL)
		return (mlx_destroy_image(data->mlx, texture.img), \
		printf(MLX_ERROR), ft_exit(data), texture);
	return (texture);
}

void	raycasting(t_cub3D *data)
{
	t_rc	*rc;
	t_ray	door_ray;

	rc = &data->rc;
	rc->per_vec = ft_get_perpendicular_vec(rc->dir_vec);
	rc->center_screen = add_2d_vec(rc->player.d_coords, rc->dir_vec);
	lauch_door_ray(data, rc, &door_ray);
	lauch_rays(data, rc);
	draw_minimap(data);
}

void	render(t_cub3D *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}

int	lauch_raycasting(t_cub3D *data)
{
	if (setup_mlx_env(data))
		return (ft_exit_and_free(data, 1, NULL, MLX_ERROR), 1);
	ft_initialize_raycasting(data);
	data->background_colors[0] = find_color(data->ident_fc, F);
	data->background_colors[1] = find_color(data->ident_fc, C);
	data->wall_textures[0] = find_texture(data, data->ident_coord, NO);
	data->wall_textures[1] = find_texture(data, data->ident_coord, SO);
	data->wall_textures[2] = find_texture(data, data->ident_coord, EA);
	data->wall_textures[3] = find_texture(data, data->ident_coord, WE);
	data->wall_textures[4] = get_tex_path(data, "./textures/door.xpm");
	data->wall_textures[5] = get_tex_path(data, "./textures/door_side.xpm");
	data->wall_textures[6] = find_texture(data, data->ident_coord, FT);
	data->wall_textures[7] = find_texture(data, data->ident_coord, CT);
	render(data);
	setup_controls_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
