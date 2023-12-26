/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:37:42 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/05/06 20:43:25 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*p;

	if ((int)nmemb < 0 || (int)size < 0)
		return ((void *)0);
	total_size = nmemb * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}

/*int main() 
{
        int i, * ptr, sum = 0;
        ptr = ft_calloc(0, sizeof(int));
        if (ptr == NULL) {
            printf("Error! memory not allocated.\n");
            exit(0);
        }
        printf("Building and calculating the sequence sum 
		of the first 10 terms\n");
        for (i = 0; i < 10; ++i) { * (ptr + i) = i;
            sum += * (ptr + i);
        }
        printf("Sum = %d\n", sum);
        free(ptr);
        return 0;
}*/