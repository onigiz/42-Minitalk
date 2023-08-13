# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:48:12 by onigiz            #+#    #+#              #
#    Updated: 2023/08/13 11:48:14 by onigiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC = server.c 
CLIENT_SRC = client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

BONUS_SERVER_SRC = server_bonus.c 
BONUS_CLIENT_SRC = client_bonus.c
BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

UTILS = utils/utils.a
NAME1 = server
NAME2 = client
BONUS_NAME1 = server_bonus
BONUS_NAME2 = client_bonus 

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: $(SERVER_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS) -o $(NAME1)

client: $(CLIENT_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS) -o $(NAME2)

$(UTILS):
	make -C ./utils

bonus: server_bonus client_bonus

server_bonus: $(BONUS_SERVER_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(BONUS_SERVER_SRC) $(UTILS) -o $(BONUS_NAME1)

client_bonus: $(BONUS_CLIENT_OBJ) $(UTILS)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_SRC) $(UTILS) -o $(BONUS_NAME2)

clean:
	make clean -C ./utils
	rm -rf *.o

fclean: clean
	make fclean -C ./utils
	rm -rf $(NAME1) $(NAME2) $(BONUS_NAME1) $(BONUS_NAME2)

re: fclean all

.PHONY: all clean fclean re
