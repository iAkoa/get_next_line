/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:23:11 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/25 19:18:01 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	while (size * count-- > 0)
		*(unsigned char *)s++ = 0;
	return (s);
}

static char	*add_line(char *line, char **buffer, int nb_letters)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = *buffer;
	line = ft_calloc(1, nb_letters + 1);
	if (!line)
		return (NULL);
	printf("temp : %s\n", temp);
	printf("*buffer : %s\n", *buffer);
	while (j != nb_letters)
	{
		line[j] = temp[j];
		j++;
	}
	printf("line : %s\n", line);
	*buffer = ft_calloc(1, ft_strlen(temp) - nb_letters + 1);
	if (!buffer)
		return (NULL);
	while (i < nb_letters)
	{
		(*buffer)[i] = temp[nb_letters + i];
		i++;
	}
	printf("petit *buffer : %s\n", *buffer);
	return (line);
}

static int	check_line(char *buffer)
{
	int		i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(ft_strlen((char*)src) + 1);
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c || c == 0)
		return ((char *)str);
	return (NULL);
}

static int	add_buffer(char **buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;

	printf("buffer : %s\n", *buffer);
	temp = *buffer;
	printf("size buffer : %i\n", ft_strlen(*buffer) + BUFFER_SIZE + 1);
	*buffer = ft_calloc(1, ft_strlen(*buffer) + BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(temp);
		return (0);
	}
	printf("temp : %s\n", temp);
	printf("buffer : %s\n", *buffer);
	while (temp && temp[i])
	{
		*buffer[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

char	*found_line(char **buffer, int fd)
{
	char	*line;
	char	*mem;
	int		i;
	int		octet;
	int		nb_letters;

	i = 0;
	printf("buffer : %s\n", *buffer);
	while (i == 0)
	{
		i = add_buffer(buffer);
		printf("i : %i\n", i);
		octet = read (fd, *buffer + i, BUFFER_SIZE);
		if (octet < 0)
			return (NULL);
		if (octet == 0)
			return (*buffer);
		nb_letters = check_line(*buffer);
		if (nb_letters > 0)
			return (add_line(line, buffer, nb_letters));
		i = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			i;
	char		*afternl;

	i = 0;
	if (!fd)
		return (0);
	printf("buffer : %s\n", buffer);
	line = found_line(&buffer, fd);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}


int	main()
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}
