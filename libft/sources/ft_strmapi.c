/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:49:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/05/09 08:49:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*strmapi;
	unsigned int		i;

	if (!s || !f)
		return (NULL);
	strmapi = ft_calloc(sizeof(*strmapi), ft_strlen(s) + 1);
	ft_strcpy(strmapi, (char *)s);
	i = 0;
	while (s[i])
	{
		strmapi[i] = (*f)(i, s[i]);
		i++;
	}
	strmapi[i] = 0;
	return (strmapi);
}

/*static	char ft_test(unsigned int index, char c)
{	
	if (index)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return (c - 1);
	}
	return (c);
}

int	main(void)
{
	char	nom[] = "Daniel Alejandro Nieto Castro";
	printf("%s\n", ft_strmapi(nom, &ft_test));
}*/