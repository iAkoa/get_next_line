/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:23:11 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/29 16:24:38 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*add_line_realloc(char **buffer, int nb_letters)
{
	int		i;
	int		j;
	char	*temp;
	char	*line;
	
	j = 0;
	i = 0;
	temp = *buffer;
	line = ft_calloc(1, nb_letters + 1);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	while (j != nb_letters)
	{
		line[j] = temp[j];
		j++;
	}
	*buffer = ft_calloc(1, ft_strlen(temp) - nb_letters + 1);
	if (!buffer)
	{	
		free(temp);
		return (NULL);
	}
	while (temp[i + nb_letters])
	{
		(*buffer)[i] = temp[nb_letters + i];
		i++;
	}
	free(temp);
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
		if (buffer[i] == '\n' || buffer[i+1] == '\0')
			return (i + 1);
		i++;
	}
	return (0);
}

static int	calloc_buffer(char **buffer)
{
	char	*temp;
	int		i;

	i = 0;

	temp = *buffer;
	*buffer = ft_calloc(1, ft_strlen(*buffer) + BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(temp);
		return (0);
	}
	if (!temp)
		return (0);
	while ((temp && temp[i]))
	{
		(*buffer)[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

char	*found_line(char **buffer, int fd)
{
	char	*line = NULL;
	int		i;
	int		octet;
	int		nb_letters;

	i = 0;
	while (i == 0)
	{
		i = calloc_buffer(buffer);
		octet = read (fd, *buffer + i, BUFFER_SIZE);
		nb_letters = check_line(*buffer);
		if (octet < 0)
			return (NULL);
		if (octet == 0)
		{
				if (!ft_strlen(*buffer))
					return (NULL);
				return (add_line_realloc(buffer, nb_letters));
		}
		if (nb_letters > 0)
			return (add_line_realloc(buffer, nb_letters));
		i = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (!fd)
		return (0);
	line = found_line(&buffer, fd);
	if (!line)
	{
		
		free(buffer);
		buffer = NULL;
	}
	return (line);
}


// int	main()
// {
// 	int fd;
	
// 	fd = open ("file.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
