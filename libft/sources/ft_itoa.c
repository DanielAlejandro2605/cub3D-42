/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:52:39 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/01/03 12:15:15 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_revstr(char *str)
{
	size_t	i;
	size_t	length;
	char	temp;

	i = 0;
	length = ft_strlen(str);
	while (i < length / 2)
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}

static int	ft_get_length_number(int number)
{
	int	size;

	if (number == -2147483648)
		return (11);
	size = 0;
	if (number < 0)
	{
		number *= -1;
		size++;
	}
	while (number > 0)
	{
		number /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size_number;
	char	*number_str;
	int		i;
	int		is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	size_number = ft_get_length_number(n);
	number_str = (char *)malloc(sizeof(char) * (size_number + 1));
	if (!number_str)
		return (NULL);
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	i = 0;
	while (n != 0)
	{
		number_str[i++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (is_neg)
		number_str[i++] = '-';
	number_str[i] = '\0';
	ft_revstr(number_str);
	return (number_str);
}
