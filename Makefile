# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 03:18:25 by gahubaul          #+#    #+#              #
#    Updated: 2016/03/05 03:18:31 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FLAG=-lmlx -framework OpenGL -framework Appkit

SRC = 	fdf.c \
		fdf_move.c

all: $(NAME)

$(NAME):
	@make -C libft
	gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a

clean:
	@make -C libft clean
	rm -f mlx

fclean: clean
	@make -C libft fclean

re: fclean all

.PHONY: all fclean clean re
