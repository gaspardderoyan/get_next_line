/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:37:53 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/12 18:05:15 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	strlen_safe(const char *s);
char	*ft_strcpy(char *dst, char *src);
size_t	calc_line_len(char *line, char *buffer, char *nl_char);
char	*join_lnb(char **line, char *buffer, char *nl_char);

#endif
