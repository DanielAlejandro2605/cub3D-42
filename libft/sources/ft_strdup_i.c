/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:34:20 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/12/26 13:34:29 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup_i(char *s, int index)
{
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (index + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < index)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
