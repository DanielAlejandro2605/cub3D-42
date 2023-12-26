/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_map_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:22:29 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:30 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_free_int_map(t_map *map, int **map_int)
{
	int	i;

	i = 0;
	if (map_int)
	{
		while (map_int && i < map->max_h)
			free(map_int[i++]);
		free(map_int);
		map_int = NULL;
	}
}

static void	ft_free_float_map(t_map *map, float **map_float)
{
	int	i;

	i = 0;
	if (map_float)
	{
		while (map_float && i < map->max_h)
			free(map_float[i++]);
		free(map_float);
		map_float = NULL;
	}
}

void	ft_free_map(t_map *map)
{
	if (map->map)
		ft_free_int_map(map, map->map);
	if (map->door_state_map)
		ft_free_int_map(map, map->door_state_map);
	if (map->timer_map)
		ft_free_float_map(map, map->timer_map);
}
