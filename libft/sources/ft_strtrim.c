/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:28:54 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/05/06 21:50:03 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isset(set, s1[start]))
		start++;
	if (start == ft_strlen(s1))
	{
		strtrim = ft_strdup("");
		if (!strtrim)
			return (NULL);
		return (strtrim);
	}
	while (end > start && ft_isset(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*int	main(void)
{
	char str[] = "[((+-Hola+Daniel!])-'";
	printf("%s\n", ft_strtrim(str, "[]()+-!'"));
}*/