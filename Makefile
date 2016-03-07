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
	@echo "\033[33;32mCompilation de la libft\t\t\tOK"
	@gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a
	@echo "\033[33;32mCompilation du programme Fdf\t\tOK"

clean:
	@rm -f $(NAME)
	@echo "\033[31mDestruction de l'executable fdf\t\tOK"
	@make -C libft clean
	@echo "Destruction des fichier .o libft\tOK"

fclean: clean
	@make -C libft fclean
	@echo "Destruction du fichier .a libft\t\tOK"

yolo:
	@echo "\033[33;32m--------------------------------------"

re: fclean yolo all

.PHONY: all fclean clean re
