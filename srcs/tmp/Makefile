# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:02:48 by tcasale           #+#    #+#              #
#    Updated: 2023/01/06 11:02:51 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= get_next_line.a

SRCS	= get_next_line.c \
		get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
AR		= ar  rcs

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $<

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) $@ $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
