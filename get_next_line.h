/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:21:07 by rmattheo          #+#    #+#             */
/*   Updated: 2021/12/02 17:09:12 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_struct
{
	int		pos;
	char	*data;

}			t_struct;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

#endif
