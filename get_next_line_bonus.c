/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:36:49 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 16:16:47 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_loop(char *buffer, char **line, int fd)
{
	int		bytes_read;
	char	*nl_char;

	while (1)
	{
		nl_char = ft_strchr(buffer, '\n');
		*line = join_lnb(line, buffer, nl_char);
		if (nl_char)
		{
			ft_strcpy(buffer, nl_char + 1);
			break ;
		}
		buffer[0] = '\0';
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			buffer[bytes_read] = 0;
		else if (bytes_read == 0)
			break ;
		else
		{
			buffer[0] = 0;
			break;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	read_loop(buffer[fd], &line, fd);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	int		fd2;
	int		i;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	if (fd <= -1)
	{
		printf("Error opening file!\n");
		return (1);
	}

	i = 0;
	while (i < 5)
	{
		printf("1: %s", get_next_line(fd));
		printf("2: %s", get_next_line(fd2));
		printf("\n");
		i++;
	}

	return (0);
}
*/
