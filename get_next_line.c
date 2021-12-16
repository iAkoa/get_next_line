/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:53:03 by rmattheo          #+#    #+#             */
/*   Updated: 2021/12/16 15:59:36 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	if (ft_strlen(buffer) < (int)start)
		return (ft_calloc(1, 1));
	if (ft_strlen(buffer) < (int)len)
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
		buffer[i] = '\0';
		*lines = ft_substr(buffer, 0, BUFFER_SIZE);
	}
	if (!ft_strchr(*lines, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
		{
			free(*lines);
			*lines = NULL;
		}
		while (i > 0 && !ft_strchr(*lines, '\n'))
		{
			buffer[i] = '\0';
			temp = *lines;
			*lines = ft_strjoin(*lines, buffer);
			// printf ("/////lines1//////%s\n", *lines);
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
	// printf ("/////lines2//////%s", *lines);
	if (!ft_strchr(*lines, '\n'))
	{
		// printf ("/////lines3//////%s\n", *lines);
		ret = ft_substr(*lines, 0, ft_strlen(*lines));
		// printf ("/////ret//////%s\n", ret);
		if (!ret)
			return (NULL);
		if (!*lines)
		{
			free(*lines);
			*lines = NULL;
			return (NULL);
		}
		// printf ("<<<<<<<ret>>>>>>%s\n", ret);
		return (ret);
	}
	i = ft_strlen(*lines);
	j = ft_strlen(ft_strchr(*lines, '\n'));
	ret = ft_substr(*lines, 0, i - j + 1);;
	temp = *lines;
	*lines = ft_substr(*lines, i - j + 1, j);
	// printf ("/////lines//////%s\n", *lines);
	free(temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*lines;

	// printf("==========> %p\n", lines);
	if (BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	ft_read(fd, &lines, buffer);
	return (ft_process(&lines));
}

// int	main()
// {
// 	int		fd;
// 	char	*line;
// 	fd = open ("file.txt", O_RDONLY);
// 	while((line = get_next_line(fd)))
// 	{
// 		printf(">>>>>>  |  %s", line);
// 		free(line);
// 	}
// 	close (fd);
// 	free(line);
// 	return (0);
// }
