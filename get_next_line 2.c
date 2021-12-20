/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:37:05 by pat               #+#    #+#             */
/*   Updated: 2021/12/20 20:14:23 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int	i;
	int j;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	d = calloc(1, sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		d[j] = s2[i];
		j++;
		i++;
	}
	return (d);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!str)
		return (NULL);
	if (!str && len > 0)
		return (NULL);
	i = ft_strlen(&str[start]);
	if (ft_strlen(str) < (int)start)
		return (ft_calloc(1, 1));
	if (ft_strlen(str) < (int)len)
		len = ft_strlen(str);
	ret = malloc((char)len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	ret = ft_memcpy(ret, &str[start], len);
	return (ret);
}

static char	*ft_return_line(char **line)
{
	int		len;
	char	*tmp;
	char 	*ret;
	int		size;

	len = 0;
	size = 0;
	tmp = *line;
	size = ft_strlen(*line);
	while ((*line)[len] != '\n' && (*line)[len] != '\0')
		len++;
	if ((*line)[len] == '\n')
	{
		ret = ft_substr(*line, 0, len + 1);
		*line = ft_substr(*line, len + 1, size);
		free(tmp);
	}
	else
	{
		ret = ft_substr(*line, 0, size);
		free(tmp);
		*line = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char 		buffer[BUFFER_SIZE + 1];
	static char *line;
	int			i;
	char		*ret;
	
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		printf ("dslkfghsdlkjhg : %i\n", i);
		buffer[i] = '\0';
		if (line == NULL)
		{
			line = ft_substr(buffer, 0, i);
		}
		else
		{
			line = ft_strjoin(line, buffer);
		}
		if (ft_strchr(line, '\n'))
		{
			break ;
		}
	}
	ret = ft_return_line(&line);
	printf("!!!!!!!!!! str : %s\n", ret);
	return (ret);
}

int	main()
{
	int		fd;
	char	*line;
	fd = open ("file1.txt", O_RDONLY);
	while(((line = get_next_line(fd)) != NULL))
	{
		
		printf(">>>>>>  |  %s\n", line);
	}
	return (0);
}
