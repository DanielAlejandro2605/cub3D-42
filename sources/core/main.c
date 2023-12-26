#include "../../includes/cub3D_struct.h"

void	data_init(t_cub3D *data)
{
	data->no = 0;
	data->so = 0;
	data->we = 0;
	data->ea = 0;
	data->f = 0;
	data->c = 0;
	data->ft = 0;
	data->ct = 0;
	data->y = -1;
	data->map_s = 4;
	data->ident_coord = NULL;
	data->ident_fc = NULL;
	data->map_list = NULL;
}

int	gnl_loop(t_cub3D *data, char *file_name)
{
	char	*line;
	int		fd;
	char	*str;

	data_init(data);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (ft_putstr_fd("Failed to open file!\n", 1), 1);
	while (line)
	{
		str = NULL;
		iter_line(data, &str, -1, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (check_full_identifier(data) < 6)
		ft_exit_and_free(data, 1, NULL, IDENT_MISSING);
	close(fd);
	if (ft_check_map(data))
		return (1);
	return (0);
}

static int	ft_check_file_str(char *f_name)
{
	int	i;
	int	length_f_name;

	length_f_name = ft_strlen_int(f_name);
	i = ft_idx_last_occur_char(f_name, '/');
	if (i >= 0 && f_name[i] == '/' && (i == (length_f_name - 1)))
		return (printf(ARG_IS_DIR), 1);
	i = ft_idx_last_occur_char(f_name, '.');
	if (i < 0 || ft_strncmp(f_name + i, ".cub", ft_strlen_int(f_name + i)))
		return (printf(INVALID_EXTENSION), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3D	data;

	if (argc == 2)
	{
		if (ft_check_file_str(argv[1]))
			return (1);
		if (gnl_loop(&data, argv[1]))
			return (ft_exit_and_free(&data, 1, NULL, NULL), 1);
		if (data.map_list)
			ft_lstclear(&data.map_list, &ft_free_map_list);
		if (lauch_raycasting(&data))
			return (1);
	}
	else
		return (printf("Invalid number of arguments\n"), 1);
	return (0);
}
