#include "get_next_line.h"

size_t	weird_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

char	*ft_join(char **line, char *buffer, char *nl_char)
{
	char	*start;
	char	*new;	
	char	*temp;
	size_t	len;

	len = weird_strlen(*line);
	if (nl_char)
		len += nl_char - buffer + 1;
	else
		len += weird_strlen(buffer);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	start = new;
	if (*line)
	{
		temp = *line;
		while (*temp)
		{
			*new = *temp;
			new++;
			temp++;
		}
	}
	while (*buffer)
	{
		*new = *buffer;
		if (*new == '\n')
		{
			new++;
			break ;
		}
		new++;
		buffer++;
	}
	*new = '\0';
	free(*line);
	return (start);
}

