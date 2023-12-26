#include "../includes/libft.h"

/*static char *new_buf(char *buf, size_t len_read)
{
    int i;
    int len;

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

static char *copy_new_line(char *line, char *buf)
{
    size_t i;
    size_t len;
    char *stock;
    
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

static size_t is_nline(char *line)
{
    int i;
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

char	  *get_next_line(int fd)
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
        return(free(line), NULL);
    return (line);
}*/

static char	*ft_read_file(int fd, char *response_static)
{
	int		num_bytes_read;
	char	*buffer_file;

	buffer_file = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_file)
		return (NULL);
	num_bytes_read = 1;
	while (num_bytes_read > 0)
	{
		num_bytes_read = read(fd, buffer_file, BUFFER_SIZE);
		if (num_bytes_read == -1)
		{
			free(buffer_file);
			return (NULL);
		}
		buffer_file[num_bytes_read] = 0;
		response_static = ft_concatenation(response_static, buffer_file);
		if (ft_strchr(buffer_file, '\n'))
			break ;
	}
	free(buffer_file);
	return (response_static);
}

static char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_advance_buffer(char *buff)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen_int(buff) - i + 1), sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		next_line[j++] = buff[i++];
	free(buff);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer_static;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer_static = ft_read_file(fd, buffer_static);
	if (!buffer_static)
		return (NULL);
	line = ft_get_line(buffer_static);
	buffer_static = ft_advance_buffer(buffer_static);
	return (line);
}
