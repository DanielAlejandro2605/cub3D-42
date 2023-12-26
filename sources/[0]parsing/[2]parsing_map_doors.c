/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_map_doors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:27 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:28 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_doors_state_map(t_map *map)
{
	int	i;

	map->door_state_map = ft_calloc((map->max_h + 1), sizeof(int *));
	if (!map->door_state_map)
		return (1);
	i = 0;
	while (i < map->max_h)
	{
		map->door_state_map[i] = ft_calloc(map->max_w, sizeof(int));
		if (!map->door_state_map[i])
			return (1);
		i++;
	}	
	return (0);
}

int	get_timer_map(t_map *map)
{
	int	i;

	map->timer_map = ft_calloc((map->max_h + 1), sizeof(float *));
	if (!map->timer_map)
		return (1);
	i = 0;
	while (i < map->max_h)
	{
		map->timer_map[i] = ft_calloc(map->max_w, sizeof(float));
		if (!map->timer_map[i])
			return (1);
		i++;
	}
	return (0);
}

int	doors_map(t_map *map)
{
	if (get_doors_state_map(map))
		return (1);
	if (get_timer_map(map))
		return (1);
	return (0);
}
