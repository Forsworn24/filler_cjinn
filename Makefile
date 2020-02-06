# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/19 18:38:51 by cjinn             #+#    #+#              #
#    Updated: 2020/02/06 17:03:42 by cjinn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_play/cjinn.filler

SRCS = srcs/main.c srcs/read_map_and_piece.c srcs/heat_map.c srcs/play.c srcs/free.c

FLAGS = -Wall -Wextra -Werror -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft_cjinn
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft_cjinn/libft.a

clean:
	make clean -C libft_cjinn
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft_cjinn
	rm -f $(NAME)

re: fclean all