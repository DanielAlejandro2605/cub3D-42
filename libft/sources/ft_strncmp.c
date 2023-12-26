/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:29:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:30:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	diff;
	int				i;

	if ((int)n < 0)
		return (-1);
	i = 0;
	diff = 0;
	while (i < (int)n && !diff && s1[i] && s2[i])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < (int)n && !diff && (s1[i] == '\0' || s2[i] == '\0'))
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}

/*int main(void)
{
	char	s1[] = "1234";
	char	s2[] = "1235";
	printf("%d\n", ft_strncmp(s1, s2, -1));
	return 0;
}*/
