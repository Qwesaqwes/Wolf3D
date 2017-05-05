# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 18:39:30 by jichen-m          #+#    #+#              #
#    Updated: 2016/05/20 23:14:32 by jichen-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

HEAD = ./includes/minilibx_macos/

LIB = -L ./libft/ -lft

LIB2 = -L ./includes/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

C_FILES = main.c\
			hook.c\
			error_param.c\
			draw.c\
			calcule.c\
			map.c\
			movement.c

SRC = $(addprefix ./srcs/,$(C_FILES))

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\033[1;32m"
		@echo "Processing files..."
		@make -C libft/
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(LIB2)
		@echo "\033[1;32m"
		@echo "$(NAME) has been created! :D"

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $< -I $(HEAD) -I ./libft/includes/ -I ./includes/

clean:
		@rm -rf $(OBJ)
		@echo "\033[1;32mObjects files have been removed successfully!"

fclean: clean
		@rm -rf $(NAME) ./libft/libft.a
		@echo "\033[1;32m$(NAME) has been removed! All clean ^^!"

re: fclean all
