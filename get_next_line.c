/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:23:11 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/29 17:47:57 by rmattheo         ###   ########lyon.fr   */
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
	// printf("taille de la ligne = %i\n", nb_letters + 1);
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
	// printf("\n\nBUFFER ajustement = %i\n\n", ft_strlen(temp) - nb_letters + 1);
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
	// printf("BUFFER de fonction = %s", *buffer);
	free(temp);
	if(*buffer[0] == '\0')
	{
		free(line);
		return (NULL);
	}
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
		if (buffer[i] == '\n' || buffer[i + 1] == '\0')
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
	// printf("taille strlen = %i\n", ft_strlen(*buffer));
	*buffer = ft_calloc(1, ft_strlen(*buffer) + BUFFER_SIZE + 1);
	// printf("BUFFER = %s\n", *buffer);
	// printf("taille calloc = %i\n", ft_strlen(*buffer) + BUFFER_SIZE + 1);
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
			{
				return (NULL);
			}
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
// 	char *line;
	
// 	fd = open ("file.txt", O_RDONLY);
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("\nline  |  %s", line);
// 		free(line);
// 	}
// 	free(line);
// 	return (0);
// }
