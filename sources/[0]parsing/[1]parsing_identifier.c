/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]parsing_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:20:31 by abravo            #+#    #+#             */
/*   Updated: 2023/05/21 23:53:58 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	handle_new_coord(t_cub3D *data, t_type tmp, char *line, int i)
{
	t_coord	*coord_node;
	char	*path;
	int		res;

	path = NULL;
	res = get_new_coord_path(&path, line, i);
	if (res > 0)
	{
		if (res == 1)
			return (1);
		else
			return (2);
	}
	coord_node = new_coord(path, tmp);
	if (!coord_node)
		return (1);
	if (generic_lst_add_node(&data->ident_coord, (void *)coord_node,
			sizeof(t_coord)))
	{
		free (coord_node);
		return (1);
	}
	free (coord_node);
	return (0);
}

int	handle_new_fc(t_cub3D *data, t_type tmp, char *line, int i)
{
	t_fc	*fc_node;
	t_fc	temp;
	int		res;

	temp.r = -1;
	temp.g = -1;
	temp.b = -1;
	res = get_new_fc_colors(&temp, line, i, NULL);
	if (res > 0)
	{
		if (res == 1)
			return (1);
		else
			return (2);
	}
	fc_node = new_fc(&temp, tmp);
	if (!fc_node)
		return (1);
	if (generic_lst_add_node(&data->ident_fc, (void *)fc_node, sizeof(t_fc)))
	{
		free (fc_node);
		return (1);
	}
	free (fc_node);
	return (0);
}

void	delimitor(char **str, t_cub3D *data, char *line, int i)
{
	t_type	tmp;
	int		res;

	tmp = eval_ident(*str, data);
	if (tmp > 0 && (tmp < F || tmp == FT || tmp == CT))
	{
		res = handle_new_coord(data, tmp, line, i);
		if (res == 1)
			free_line_end_exit(line, data, str, MALLOC_FAIL);
		else if (res == 2)
			free_line_end_exit (line, data, str, INVALID_PATH_TEXTURE);
	}
	else if (tmp > 0 && tmp >= F && tmp <= C)
	{
		res = handle_new_fc(data, tmp, line, i);
		if (res == 1)
			free_line_end_exit(line, data, str, MALLOC_FAIL);
		else if (res == 2)
			free_line_end_exit (line, data, str, ERROR_RGB_FORMAT);
	}
	else if ((int)tmp == -1)
		free_line_end_exit (line, data, str, IDENT_INVALID);
	free(*str);
	*str = NULL;
}

int	check_map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || !line[i])
		return (0);
	if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' \
	&& line[i] != 'W' && line[i] != 'F' && line[i] != 'C')
		return (1);
	return (0);
}

void	iter_line(t_cub3D *data, char **str, int i, char *line)
{
	if (check_full_identifier(data) < 6)
	{
		if (check_map_start(line))
			ft_exit_and_free(data, 1, &line, IDENT_INVALID);
		while (line[++i])
		{
			if (line[i] == ' ' && line[i] != '\n' && line[i])
				delimitor(str, data, line, i);
			else if (line[i] != ' ' && line[i])
			{
				get_char(line[i], str);
				if (!*str)
					ft_exit_and_free(data, 1, &line, MALLOC_FAIL);
			}
		}
	}
	else if (check_full_identifier(data) == 6)
	{
		data->y = data->y + 1;
		if (handle_new_line_map(data, line, data->y))
			ft_exit_and_free(data, 1, &line, MALLOC_FAIL);
	}
	free(*str);
}

// Function to parse the file map in a liked list
// int	get_list(t_cub3D *data, char *line)
// {
// 	int		i;
// 	char	*str;	

// 	i = -1;
// 	str = NULL;
// 	iter_line(data, &str, i, line);
// 	return (0);
// }

//Function to check if the likeds list are created
// void __debug_parsing(t_cub3D *data)
// {
//     t_list *iter = data->ident_coord;
//     t_coord  *current = NULL;
//     while (iter)
//     {
//         current = (t_coord*) iter->content;
//         printf("{%d}[%s]\n", current->id, current->path);
//         iter = iter->next;
//     }

// 	t_list *iter2 = data->ident_fc;
//     t_fc  *cur = NULL;
//     while (iter2)
//     {
//         cur = (t_fc*) iter2->content;
//         printf("{%d}(%d)(%d)(%d)\n", cur->id, cur->r, cur->g, cur->b);
//         iter2 = iter2->next;
//     }
// 	t_list *iter3 = data->map_list;
//     t_map_list  *current3 = NULL;
//     while (iter3)
//     {
//         current3 = (t_map_list*) iter3->content;
//         printf("{%s}(%d)[%d]\n", current3->line, current3->_y, current3->_x);
//         iter3 = iter3->next;
//     }
// }