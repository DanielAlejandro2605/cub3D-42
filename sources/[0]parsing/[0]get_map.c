/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:21 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_initialize_map(t_list **lst, t_map *map)
{
	if (map->l_idx == -1)
		map->max_h = ft_lstsize(*lst) - map->b_idx;
	else
		map->max_h = map->l_idx - map->b_idx;
	map->valide_map = 1;
	map->player._is_set = 0;
	map->map = (int **)malloc(sizeof(int *) * (map->max_h + 1));
	if (!map->map)
		return (1);
	return (0);
}

static void	create_tab_ln(int *map_l, char *l, int max_w, int full)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if ((int)l[i] == 10)
			break ;
		else if ((int)l[i] >= 48 && (int)l[i] <= 50)
			map_l[i] = (int)l[i] - '0';
		else
			map_l[i] = (int)l[i];
		i++;
	}
	if (full != 1)
	{
		while (i < (max_w))
		{
			map_l[i] = 32;
			i++;
		}
	}
}

static int	ft_create_map_from_list(t_list **lst, t_map *map)
{
	t_list	*aux;
	char	*line;
	int		i;

	aux = *lst;
	i = 0;
	while (i++ < map->b_idx)
		aux = aux->next;
	while (aux)
	{
		line = ((t_map_list *)(aux->content))->line;
		map->map[i - map->b_idx - 1] = (int *)malloc(sizeof(int) * map->max_w);
		if (!map->map[i - map->b_idx - 1])
			return (ft_free_map(map), 1);
		if (((t_map_list *)(aux->content))->_x < map->max_w)
			create_tab_ln(map->map[i - map->b_idx - 1], line, map->max_w, 0);
		else
			create_tab_ln(map->map[i - map->b_idx - 1], line, map->max_w, 1);
		if (i == map->l_idx)
			break ;
		aux = aux->next;
		i++;
	}
	return (0);
}

int	ft_get_map(t_list **lst, t_map *map)
{
	map->b_idx = -1;
	map->max_w = -1;
	map->l_idx = -1;
	if (ft_check_map_lst(lst, map))
		return (1);
	if (ft_initialize_map(lst, map))
		return (1);
	if (ft_create_map_from_list(lst, map))
		return (1);
	return (0);
}
