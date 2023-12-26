/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:45:56 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/12/22 16:30:18 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_concatenation(char *str_join, char *str_add)
{
	char	*temp_concatenation;

	if (str_join)
	{
		temp_concatenation = ft_strjoin_secure(str_join, str_add);
		free (str_join);
		if (!temp_concatenation)
			return (NULL);
	}
	else
	{
		temp_concatenation = ft_strdup(str_add);
		if (!temp_concatenation)
			return (NULL);
	}
	return (temp_concatenation);
}
