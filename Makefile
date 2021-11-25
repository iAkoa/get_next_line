# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:45:37 by rmattheo          #+#    #+#              #
#    Updated: 2021/11/18 16:42:07 by rmattheo         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strncmp.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_strrchr.c	\
			ft_calloc.c		\
			ft_strdup.c 	\
			ft_substr.c		\
			ft_strtrim.c	\
			ft_putchar_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_strmapi.c	\
			ft_strmapi.c	\
			ft_putendl_fd.c	\
			ft_striteri.c	\
			ft_split.c		\
			ft_strjoin.c	\
			ft_itoa.c

SRCS_BONUS	=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstsize.c	

OBJS    = ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME    = libft.a

CC        = clang

CFLAGS    = -Wall -Wextra -Werror

HEADER = libft.h

%o : %c ${HEADER} Makefile
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:    ${OBJS}
		ar -rcs ${NAME} ${OBJS}
		
bonus: 	${OBJS} ${OBJS_BONUS}
		ar -rcs ${NAME} ${OBJS} ${OBJS_BONUS}

all:    ${NAME}

clean:
		rm -f ${OBJS} ${OBJS_BONUS}

fclean:    clean
		rm -f ${NAME}

re:        fclean all

.PHONY:    all clean fclean re bonus
