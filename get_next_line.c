/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:36:49 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/12 17:37:35 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (bytes_read >= 0)
			buffer[bytes_read] = 0;
		if (bytes_read <= 0)
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

/*
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
*/
