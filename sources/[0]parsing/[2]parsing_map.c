#include "../../includes/cub3D_struct.h"

static int	ft_check_empty_space(t_map *map, int y, int x, int empty)
{
	if (y == 0 || y == (map->max_h - 1))
		return (1);
	else if (x == 0 || x == (map->max_w - 1))
		return (1);
	ft_scan_point_area(map, y, x, empty);
	return (0);
}

static int	ft_check_doors(t_map *map, int y, int x)
{
	if (y == 0 || y == (map->max_h - 1))
		return (1);
	else if (x == 0 || x == (map->max_w - 1))
		return (1);
	if (map->map[y - 1][x] == 1 || map->map[y + 1][x] == 1)
	{
		if ((map->map[y - 1][x] != 1 || map->map[y + 1][x] != 1)
			|| (map->map[y][x - 1] != 0 || map->map[y][x + 1] != 0))
		{
			return (1);
		}
		else
		{
			map->map[y][x] = VERTICAL_DOOR;
		}
	}
	else if (map->map[y][x - 1] == 1 || map->map[y][x + 1] == 1)
	{
		if ((map->map[y][x - 1] != 1 || map->map[y][x + 1] != 1)
			|| (map->map[y - 1][x] != 0 || map->map[y + 1][x] != 0))
		{
			return (1);
		}
	}
	return (0);
}

static int	ft_scan_map(t_map *map, int i, int j)
{
	while (i < map->max_h)
	{
		j = 0;
		while (j < map->max_w)
		{
			if (ft_check_player(map, map->map[i][j], i, j))
				return (1);
			if (map->map[i][j] == 32)
				ft_scan_point_area(map, i, j, 1);
			else if (map->map[i][j] == 0)
			{
				if (ft_check_empty_space(map, i, j, 0))
					return (printf(MAP_UNCLOSED), 1);
			}
			else if (map->map[i][j] == 2)
			{
				if (ft_check_doors(map, i, j))
					return (printf(INVALID_DOOR_POS), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(t_cub3D *data)
{
	t_map	map;
	int		i;
	int		j;

	map.door_state_map = NULL;
	map.timer_map = NULL;
	i = 0;
	j = 0;
	if (ft_get_map(&data->map_list, &map))
		return (1);
	if (ft_scan_map(&map, i, j))
		return (ft_free_map(&map), 1);
	if (!map.valide_map)
		return (ft_free_map(&map), 1);
	if (!map.player._is_set)
		return (printf (PLAYER_NONE), ft_free_map(&map), 1);
	if (doors_map(&map))
		return (ft_free_map(&map), 1);
	data->map = map;
	return (0);
}
