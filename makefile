# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onigiz <onigiz@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 18:46:06 by onigiz            #+#    #+#              #
#    Updated: 2023/07/26 18:46:11 by onigiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./

CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client

SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server

BONUS-CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client

BONUS_SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server

CLIENT_NAME = client

SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):
	$(CLIENT)
$(SERVER_NAME):
	$(SERVER)

bonus: $(CLIENT_NAME) $(SERVER_NAME)
	$(BONUS_CLIENT)

clean:
	rm -rf client server
fclean: clean

re: clean all

.PHONY: all clean fclean re
