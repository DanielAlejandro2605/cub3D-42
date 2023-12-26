/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:46:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	number;

	number = (long int)n;
	if (number < 0)
	{
		number = number * -1;
		write(fd, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
	else
		ft_putchar_fd(number + '0', fd);
}

/*int	main(int argc, char **argv)
{
	int	fd;
	if (argc)
	{
		fd = open(argv[1], O_WRONLY);
		if (fd == -1)
			printf("Failed to open the file %s\n", argv[1]);
		ft_putnbr_fd(2147483647, fd);
		close(fd);	
	}
}*/