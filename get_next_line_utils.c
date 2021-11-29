/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:19:02 by pat               #+#    #+#             */
/*   Updated: 2021/11/29 14:26:57 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(ft_strlen((char*)src) + 1);
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
void	*ft_calloc(int count, int size)
{
	void	*s;
	int		i;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	i = 0;
	while (++i < size * count)
		((unsigned char *)s)[i] = 0;
	return (s);
}