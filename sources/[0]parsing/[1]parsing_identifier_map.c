/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]parsing_identifier_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:20:31 by abravo            #+#    #+#             */
/*   Updated: 2023/05/21 22:35:40 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_map_list	*new_map_list(char *line, int y)
{
	t_map_list	*elem;

	elem = malloc(sizeof(t_map_list));
	if (!elem)
		return (NULL);
	elem->line = ft_strdup(line);
	if (!elem->line)
	{
		free (elem);
		return (NULL);
	}
	elem->_y = y;
	elem->_x = ft_len_until_nl(line);
	return (elem);
}

int	handle_new_line_map(t_cub3D *data, char *line, int y)
{
	t_map_list	*new_line_node;

	new_line_node = new_map_list(line, y);
	if (!new_line_node)
		return (1);
	if (generic_lst_add_node(&data->map_list, (void *)new_line_node,
			sizeof(t_map_list)))
	{
		free (new_line_node);
		return (1);
	}
	free (new_line_node);
	return (0);
}
