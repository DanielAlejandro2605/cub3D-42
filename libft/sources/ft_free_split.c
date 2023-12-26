/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:58:41 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/25 22:58:41 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_split(char **s)
{
	long unsigned int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
}
