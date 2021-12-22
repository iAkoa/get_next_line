/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:19:02 by pat               #+#    #+#             */
/*   Updated: 2021/12/20 23:38:05 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if(!str[i])
		return (0);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c || c == 0)
	{
		return (i);
	}
	return (0);
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