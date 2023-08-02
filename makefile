# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 14:45:22 by onigiz            #+#    #+#              #
#    Updated: 2023/08/01 14:45:27 by onigiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= server

NAME2	= client

SRC		= server.c client.c

OBJ		= $(SRC:.c=.o)

all : $(OBJ)
	@make -C ./utils
	@gcc -Wall -Wextra -Werror server.c ./utils/libftprintf.a -o $(NAME1)
	@gcc -Wall -Wextra -Werror client.c ./utils/libftprintf.a -o $(NAME2)

clean :
	@make clean -C ./utils
	@rm -rf client.o server.o

fclean : clean
	@make fclean -C ./utils
	@rm -rf $(NAME1) $(NAME2)

re : fclean all
.PHONY: clean fclean all re