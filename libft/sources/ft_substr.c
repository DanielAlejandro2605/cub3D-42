/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:39:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:30:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_get_null_string(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (0);
	ret[0] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			length_s;

	if (!s)
		return (NULL);
	length_s = ft_strlen(s);
	if ((size_t)start > length_s)
		return (ft_get_null_string());
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len && i < length_s)
	{
		str[i] = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
