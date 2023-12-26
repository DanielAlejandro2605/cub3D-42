/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:02:21 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/28 13:26:09 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	negative;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = -1;
	else
		negative = 1;
	if (negative == -1 || str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * negative);
}

/*int main()
{
	printf("%d\n", ft_atoi("  -43"));
	printf("%d\n", ft_atoi("  0"));
	printf("%d\n", ft_atoi("  -1"));
	printf("%d\n", ft_atoi("  -2103823Q"));
	printf("%d\n", ft_atoi("  3927293"));
	printf("%d\n", ft_atoi("  12"));
	printf("%d\n", ft_atoi("\v2"));
}*/