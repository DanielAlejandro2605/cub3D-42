/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:08:38 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/26 12:01:40 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

/*int	main(int argc, char **argv)
{
	int	fd;
	if (argc)
	{
		fd = open(argv[1], O_WRONLY);
		if (fd == -1)
			printf("Failed to open the file %s\n", argv[1]);
		ft_putchar_fd('D', fd);
		ft_putchar_fd('a', fd);
		ft_putchar_fd('n', fd);
		ft_putchar_fd('i', fd);
		ft_putchar_fd('e', fd);
		ft_putchar_fd('l', fd);
		close(fd);	
	}
}*/