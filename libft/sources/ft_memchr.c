/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:09:44 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 47;
   size_t len = 4;
   char *ret;

   ret = memchr(str, ch, len);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/