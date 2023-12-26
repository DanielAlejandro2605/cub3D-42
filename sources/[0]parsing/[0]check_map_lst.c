/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]check_map_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:33:45 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/05/03 17:37:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_len_until_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static int	ft_valid_map_char(char c)
{
	if ((c >= '0' && c <= '2')
		|| (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
	{
		return (1);
	}
	return (-1);
}

static int	ft_consider_line(char *line)
{
	int	i;
	int	flag_not_char_map;

	flag_not_char_map = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			flag_not_char_map = ft_valid_map_char(line[i]);
			if (flag_not_char_map == -1)
				return (-1);
		}
		i++;
	}
	if (flag_not_char_map == 0)
		return (0);
	return (1);
}

/*
Here we find the index (in the linked list) of the first line of
the map in the file checking (using ft_consider_line function) if in
the line contains at least one '0', '1', 'W', 'S', 'E', 'W'
*/

static int	ft_check_end_of_the_map(t_list **lst, t_map *map, int *i)
{
	t_list	*aux;
	int		is_valid_line;
	int		idx;

	idx = *i;
	aux = generic_get_node_by_idx(lst, idx);
	while (aux)
	{
		is_valid_line = ft_consider_line(((t_map_list *)(aux->content))->line);
		if (is_valid_line == -1)
			return (printf(INVALID_SYMBOL_MAP), 1);
		else if (is_valid_line == 0 && map->l_idx == -1)
			map->l_idx = idx;
		else if (is_valid_line == 1 && map->l_idx != -1)
			return (printf(MAP_IS_NOT_LAST_ELEM), 1);
		if (ft_len_until_nl(((t_map_list *)(aux->content))->line) > map->max_w)
			map->max_w = ft_len_until_nl(((t_map_list *)(aux->content))->line);
		idx++;
		aux = aux->next;
	}
	return (0);
}

int	ft_check_map_lst(t_list **lst, t_map *map)
{
	t_list	*aux;
	int		is_valid_line;
	int		i;

	aux = *lst;
	i = 0;
	while (aux)
	{
		is_valid_line = ft_consider_line(((t_map_list *)(aux->content))->line);
		if (is_valid_line == -1)
			return (printf(INVALID_SYMBOL_MAP), 1);
		else if (is_valid_line == 1 && map->b_idx == -1)
			map->b_idx = i;
		else if (is_valid_line >= 0 && map->b_idx != -1)
		{
			if (!ft_check_end_of_the_map(lst, map, &i))
				break ;
			return (1);
		}
		i++;
		aux = aux->next;
	}
	return (0);
}
