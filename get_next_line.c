/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:53:03 by rmattheo          #+#    #+#             */
/*   Updated: 2021/12/15 19:08:02 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c || c == 0)
		return ((char *)str);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	*ft_memcpy(void *dest, const void *src, int n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = n;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest - i);
}
void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, (count * size));
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	d = malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	d[i] = 0;
	while (*s1)
		*d++ = *s1++;
	while (*s2)
		*d++ = *s2++;
	return (d - i);
}

char	*ft_substr(char const *buffer, unsigned int start, size_t len)
{
	char	*lines;
	size_t	i;

	if (!buffer && len > 0)
		return (NULL);
	if (!buffer)
		return (NULL);
	i = ft_strlen(&buffer[start]);
	if (ft_strlen(buffer) < start)
		return (ft_calloc(1, 1));
	if (ft_strlen(buffer) < len)
		len = ft_strlen(buffer);
	lines = malloc((char)len + 1);
	if (!lines)
		return (NULL);
	lines[len] = 0;
	lines = ft_memcpy(lines, &buffer[start], len);
	return (lines);
}

void	ft_read(int fd, char **lines, char *buffer)
{
	char	*temp;
	int		i;

	if (!*lines)
	{
		i = read(fd, buffer, BUFFER_SIZE);
	printf ("<<<<I>>>>%i\n", i);
		buffer[i] = '\0';
	printf ("\nbuffer : %s\n", buffer);
		*lines = ft_substr(buffer, 0, BUFFER_SIZE);
	printf ("\nline : %s\n", *lines);
	}
	if (!ft_strchr(*lines, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while (i > 0 && !ft_strchr(*lines, '\n'))
		{
			buffer[i] = '\0';
			temp = *lines;
			*lines = ft_strjoin(*lines, buffer);
			free(temp);
			if (ft_strchr(*lines, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
}

char	*ft_process(char **lines)
{
	char	*temp;
	char	*ret;
	int		i;
	int		j;
	if (!*lines)
		return (NULL);
	printf ("\n<<<<<line>>>>> : %s\n", *lines);
	if (!ft_strchr(*lines, '\n'))
	{
		if (*lines && *lines[0] == '\0')
		{
			free(*lines);
			*lines = NULL;
			return (NULL);
		}

		ret = ft_substr(*lines, 0, ft_strlen(*lines));
		free (*lines);
		return (ret);
	}
	i = ft_strlen(*lines);
	j = ft_strlen(ft_strchr(*lines, '\n'));
	ret = ft_substr(*lines, 0, i - j);
	temp = *lines;
	*lines = ft_substr(*lines, i - j + 1, j);
	free(temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*lines;

	if (BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	ft_read(fd, &lines, buffer);
	return (ft_process(&lines));
}

int	main()
{
	int		fd;
	char	*line;

	fd = open ("file.txt", O_RDONLY);
	while((line = get_next_line(fd)))
	{
		printf(">>>>>>  |  %s\n", line);
		free(line);
	}
	close (fd);
	free(line);
	return (0);
}
