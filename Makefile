# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrapat <ccrapat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 19:09:11 by ccrapat           #+#    #+#              #
#    Updated: 2014/12/02 06:57:51 by ccrapat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -I includes -I libft/includes -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
SRC = main.c \
	  check_args.c \
	  create_lst.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
