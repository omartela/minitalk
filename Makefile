# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 10:26:49 by omartela          #+#    #+#              #
#    Updated: 2024/08/01 10:49:25 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
NAME_C := client
NAME_S := server
SRCS_C := src/client.c
SRCS_S := src/server.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

LIBS = src/libft/libft.a
CFLAGS = -g -Wall -Wextra -Werror -I$(INCLUDES)
INCLUDES = includes/

LIBFT_DIR = src/libft

all: libft $(NAME_C) $(NAME_S)

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_C): $(OBJS_C)
	$(CC) $(OBJS_C) $(LIBS) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(OBJS_S) $(LIBS) -o $(NAME_S)

clean:
	$(RM) $(OBJS_C)
	$(RM) $(OBJS_S)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft