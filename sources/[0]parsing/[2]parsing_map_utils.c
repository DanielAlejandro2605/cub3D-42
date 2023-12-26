#include "../../includes/cub3D_struct.h"

static void	ft_scan_around(t_map *map, int y, int x, int error_int)
{
	if ((x < 0 || x == map->max_w) || (y < 0 || y == map->max_h))
		return ;
	if (map->map[y][x] == error_int)
	{
		if (map->valide_map)
			printf(MAP_UNCLOSED);
		map->valide_map = 0;
	}
}

void	ft_scan_point_area(t_map *map, int y, int x, int empty)
{
	int	error_int;

	if (empty)
		error_int = 0;
	else
		error_int = 32;
	ft_scan_around(map, y + 1, x, error_int);
	ft_scan_around(map, y - 1, x, error_int);
	ft_scan_around(map, y, x + 1, error_int);
	ft_scan_around(map, y, x - 1, error_int);
}
