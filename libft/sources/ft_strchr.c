/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:31:26 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char )c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int main (void)
{
    char str[10] = "Daniel";
	// char s[] = "tripouille";
    char *occurence = ft_strchr(str, 'D' + 256);
    printf("%s\n", occurence);
    return (0);
}*/
