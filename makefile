# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:48:12 by onigiz            #+#    #+#              #
#    Updated: 2023/08/16 18:11:19 by onigiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC = server.c 
CLIENT_SRC = client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

UTILS = utils/utils.a
NAME1 = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: $(SERVER_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS) -o $(NAME1)

client: $(CLIENT_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS) -o $(NAME2)

$(UTILS):
	make -C ./utils
	
clean:
	make clean -C ./utils
	rm -rf *.o

fclean: clean
	make fclean -C ./utils
	rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
