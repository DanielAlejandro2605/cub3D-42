/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]parsing_identifier_free.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:20:31 by abravo            #+#    #+#             */
/*   Updated: 2023/07/19 18:29:57 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_free_fc(void *content)
{
	free(content);
}

void	ft_free_coord(void *content)
{
	t_coord	*tmp;

	tmp = (t_coord *)content;
	free(tmp->path);
	free(tmp);
}

void	ft_free_map_list(void *content)
{
	t_map_list	*tmp;

	tmp = (t_map_list *)content;
	free(tmp->line);
	free(tmp);
}

void	ft_exit_and_free(t_cub3D *data, int ret, char **str, char *error_msg)
{
	if (error_msg)
		printf("%s", error_msg);
	if (str)
		free (*str);
	if (data->ident_coord)
		ft_lstclear(&data->ident_coord, &ft_free_coord);
	if (data->ident_fc)
		ft_lstclear(&data->ident_fc, &ft_free_fc);
	if (data->map_list)
		ft_lstclear(&data->map_list, &ft_free_map_list);
	close (data->fd);
	exit(ret);
}

void	free_line_end_exit(char *line, t_cub3D *data, char **str, char *error)
{
	free (line);
	ft_exit_and_free(data, 1, str, error);
}
