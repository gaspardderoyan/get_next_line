#include "get_next_line.h"

void	read_loop(char *buffer, char **line, int fd)
{
	int		bytesRead;
	char	*nl_char;
	size_t	len;

	while (1)
	{
		nl_char = ft_strchr(buffer, '\n');
		len = calc_line_len(*line, buffer, nl_char);
		*line = ft_join(line, buffer, len);
		if (nl_char)
		{
			ft_strcpy(buffer, nl_char + 1);
			break ;
		}
		buffer[0] = '\0';
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead >= 0)
			buffer[bytesRead] = 0;
		if (bytesRead <= 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	line = NULL;
	read_loop(buffer, &line, fd);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	int		i;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd <= -1)
	{
		printf("Error opening file!\n");
		return (1);
	}

	i = 0;
	while (i < 50)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		printf("%s", res);
		sleep(1);
		free(res);
		i++;
	}

	return (0);
}
