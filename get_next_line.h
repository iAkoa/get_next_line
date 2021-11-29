/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:07 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/26 00:36:40 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
void		*ft_calloc(int count, int size);
int			ft_strlen(char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *src);
char		*found_line(char **buffer, int fd);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

#endif
