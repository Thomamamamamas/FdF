# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:32:54 by tcasale           #+#    #+#              #
#    Updated: 2021/12/14 14:13:11 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= fdf.c \
	fdf_utils.c \
	fdf_isometric.c \
	fdf_mlx.c \
	fdf_graphic.c \
	fdf_parsing.c \
	fdf_debug_utils.c

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FDFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

%.o: %.c
			${CC} -c ${CFLAGS} -o ${FDFLAGS} $@ $<

all:	$(NAME)

$(NAME):	$(OBJS)

clean:	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
