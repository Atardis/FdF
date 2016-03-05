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

NAME=mlx
FLAG=-lmlx -framework OpenGL -framework Appkit

SRC = 	fdf.c \
		fdf_move.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a

clean:
	rm -f mlx

re: clean all

.PHONY: all clean re
