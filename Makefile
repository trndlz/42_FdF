# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmervin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 12:30:26 by tmervin           #+#    #+#              #
#    Updated: 2018/04/19 11:54:55 by tmervin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRC_PATH	= ./SRC_PATH

SRC_NAME	=	main.c		\
				draw.c		\
				read.c

OBJ_PATH	= ./src

LDFLAGS		= -Llibft
LDLIBS		= -lft

CC			= gcc
CFLAGS		= -Werror -Wall -Wextra

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

RM			= rm -fv

MINILIBX	= -L ./minilibx/ -lmlx -framework OpenGL -framework Appkit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(MINILIBX) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)$.c
	@mkdir %(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make clean -C libft/
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
