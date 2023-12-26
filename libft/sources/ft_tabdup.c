/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:26:45 by gamoreno          #+#    #+#             */
/*   Updated: 2023/01/14 00:44:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_strintab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

char	**ft_tabdup(char **origin_tab)
{
	char	**ret_tab;
	int		i;

	if (!origin_tab)
		return (NULL);
		i = 0;
	ret_tab = (char **)malloc(sizeof(char *) * (ft_strintab(origin_tab) + 1));
	if (!ret_tab)
		ft_free_tab(ret_tab);
	while (origin_tab[i])
	{
		ret_tab[i] = ft_strdup(origin_tab[i]);
		if (!ret_tab[i])
		{
			ft_free_tab(ret_tab);
			return (NULL);
		}
		i++;
	}
	ret_tab[i] = NULL;
	return (ret_tab);
}
