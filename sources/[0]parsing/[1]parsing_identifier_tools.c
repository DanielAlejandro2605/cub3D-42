/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]parsing_identifier_tools.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:20:31 by abravo            #+#    #+#             */
/*   Updated: 2023/05/21 21:11:40 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_char(char c, char **str)
{
	char	*tmp;

	if (!*str)
	{
		*str = ft_strdup("?");
		if (!*str)
		{
			*str = NULL;
			return (1);
		}
		*str[0] = c;
		return (0);
	}
	tmp = ft_strjoin(*str, "?");
	free(*str);
	if (!tmp)
	{
		*str = NULL;
		return (1);
	}
	tmp[ft_strlen(tmp) - 1] = c;
	*str = tmp;
	return (0);
}

int	check_full_identifier(t_cub3D *data)
{
	int	check;

	check = data->no + data->so + data->we + data->ea + data->f + data->c;
	if (check > 0)
		return (check);
	return (0);
}

int	is_identical(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0');
}

t_type	eval_ident_fct(char *ident, t_cub3D *data)
{
	if (is_identical("FT", ident))
	{
		if (data->ft == 0)
		{
			data->ft = 1;
			return (FT);
		}
		return (-1);
	}
	else if (is_identical("CT", ident))
	{
		if (data->ct == 0)
		{
			data->ct = 1;
			return (CT);
		}
		return (-1);
	}
	return (UNASSIGNED);
}

// t_type	eval_ident_dflt(char *ident, t_cub3D *data)
// {
// 	if (is_identical("DF", ident))
// 	{
// 		if (data->ft == 0)
// 		{
// 			data->df = 1;
// 			return (DF);
// 		}
// 		return (-1);
// 	}
// 	else if (is_identical("DL", ident))
// 	{
// 		if (data->ct == 0)
// 		{
// 			data->dl = 1;
// 			return (DL);
// 		}
// 		return (-1);
// 	}
// 	return (UNASSIGNED);
// }

// Function to return corresponding token from string
t_type	eval_ident(char *ident, t_cub3D *data)
{
	if (is_identical("NO", ident))
		return (eval_ident_coord(ident, data));
	else if (is_identical("SO", ident))
		return (eval_ident_coord(ident, data));
	else if (is_identical("WE", ident))
		return (eval_ident_coord_bis(ident, data));
	else if (is_identical("EA", ident))
		return (eval_ident_coord_bis(ident, data));
	else if (is_identical("F", ident))
		return (eval_ident_fc(ident, data));
	else if (is_identical("C", ident))
		return (eval_ident_fc(ident, data));
	else if (is_identical("FT", ident))
		return (eval_ident_fct(ident, data));
	else if (is_identical("CT", ident))
		return (eval_ident_fct(ident, data));
	return (UNASSIGNED);
}
