# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:32:54 by tcasale           #+#    #+#              #
#    Updated: 2021/12/13 17:41:55 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf.a

SRC	= fdf.c \
	fdf_utils.c \
	fdf_isometric.c \
	fdf_mlx.c
	fdf_graphicals.c \
	fdf_parsing.c \
	fdf_debug_utils.c

OBJ	=${SRCS:.c=.o}

Header	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJ)
				$(AR) $@ $<
