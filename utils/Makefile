# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 16:16:02 by onigiz            #+#    #+#              #
#    Updated: 2023/03/15 16:16:17 by onigiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

list=ft_printf.c \
		ft_printf_num.c \
		ft_printf_others.c \
		ft_printf_utils.c \
		ft_atoi.c

OBJS = $(list:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean ${NAME}
.PHONY: clean fclean all re
