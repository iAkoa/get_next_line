/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:07 by rmattheo          #+#    #+#             */
/*   Updated: 2021/12/22 14:04:53 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memcpy(void *dest, const void *src, int n);
int			ft_strlen(const char *s);
int			ft_strchr(char *str, int c);
char		*ft_substr(char const *buffer, unsigned int start, size_t len);
void		ft_read(char **lines, char *buffer, int fd, int *i);
char	*ft_return_line(char **line);
char		*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 110
# endif

#endif
