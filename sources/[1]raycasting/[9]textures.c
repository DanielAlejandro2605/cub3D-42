/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [9]textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:11 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:57 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_tex	find_texture(t_cub3D *data, t_list *ident_coord, unsigned int type)
{
	char		*path;
	t_tex		texture;

	texture = (t_tex){NULL, NULL, 0, 0, 0, 0, 0};
	while (ident_coord && ((t_coord *)(ident_coord->content))->id != type)
		ident_coord = ident_coord->next;
	if (ident_coord == NULL)
		return (texture);
	path = ((t_coord *)(ident_coord->content))->path;
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
