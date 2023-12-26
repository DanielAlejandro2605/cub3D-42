/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:56 by dnieto-c          #+#    #+#             */
/*   Updated: 2023/07/19 18:26:10 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*new_buf(char *buf, size_t len_read)
{
	int	i;
	int	len;

	len = ft_strlen_int(buf + len_read);
	if (len)
		ft_memcpy(buf, buf + len_read, len);
	i = 0;
	while ((i + len) < BUFFER_SIZE && buf[i + len])
	{
		buf[i + len] = '\0';
		i++;
	}
	return (buf);
}

static char	*copy_new_line(char *line, char *buf)
{
	size_t	i;
	size_t	len;
	char	*stock;

	len = ft_strlen_int(line);
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	stock = malloc(sizeof(char) * (len + i + 1));
	if (!stock)
		return (NULL);
	stock[len + i] = '\0';
	ft_memcpy(stock, line, len);
	ft_memcpy(&stock[len], buf, i);
	new_buf(buf, i);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (stock);
}

static size_t	is_nline(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		count;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count = 1;
	line = NULL;
	while (!is_nline(line) && count)
	{
		if (!buf[0])
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count < 0)
				count = 0;
			buf[BUFFER_SIZE] = '\0';
		}
		line = copy_new_line(line, buf);
		if (!line)
			break ;
	}
	if (!line || !line[0])
		return (free(line), NULL);
	return (line);
}
