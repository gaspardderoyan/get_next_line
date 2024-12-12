#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	strlen_safe(const char *s);
char	*ft_strcpy(char *dst, char *src);
size_t	calc_line_len(char *line, char *buffer, char *nl_char);
char	*ft_join(char **line, char *buffer, size_t len);

#endif
