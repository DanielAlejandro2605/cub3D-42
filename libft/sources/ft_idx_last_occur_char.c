/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idx_last_occur_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:59:33 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/01/14 01:55:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_idx_last_occur_char(char *str, char c)
{
	int	last_occur;

	last_occur = ft_strlen_int(str) - 1;
	while (last_occur > -1 && str[last_occur] && str[last_occur] != c)
		last_occur--;
	if (last_occur > 0)
		return (last_occur);
	else if (last_occur == 0 && str[0] == c)
		return (last_occur);
	else
		return (-1);
}
