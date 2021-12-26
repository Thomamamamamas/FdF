# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:32:54 by tcasale           #+#    #+#              #
#    Updated: 2021/12/26 17:54:56 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= fdf.c \
	fdf_utils.c \
	fdf_isometric.c \
	fdf_mlx.c \
	fdf_graphic.c \
	fdf_color.c \
	fdf_parsing.c \
	fdf_debug_utils.c

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FDFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

%.o: %.c
			${CC} ${CFLAGS} -I./libft/libft.a -I./get_next_line/get_next_line.a -Imlx -c  $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) ./libft/libft.a ./get_next_line/get_next_line.a
			$(CC) $(OBJS) $(FDFLAGS) ./libft/libft.a ./get_next_line/get_next_line.a -o $(NAME)

./libft/libft.a:
	$(MAKE) -C ./libft

./get_next_line/get_next_line.a:
	$(MAKE) -C ./get_next_line

clean:
		$(MAKE) -C ./libft $@
		$(MAKE) -C ./get_next_line $@
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ./libft $@
		$(MAKE) -C get_next_line $@
		${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
