#include "get_next_line.h"
#define BUFFER_SIZE 42

void	read_loop(char *buffer, char **line, int fd)
{
	int	bytesRead;
	char	*nl_char;
	while (1)
	{
		nl_char = ft_strchr(buffer, '\n');
		*line = ft_join(line, buffer, nl_char);
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

	line = NULL;
	read_loop(buffer, &line, fd);
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
		printf("%s", res);
		free(res);
		i++;
	}

	return (0);
}
