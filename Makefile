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
	@echo "\033[33;32mCompilation de la libft\t\t\t | OK |"
	@gcc -o $(NAME) $(SRC) $(FLAG) libft/libft.a
	@echo "\033[33;32mCompilation du programme Fdf\t\t | OK |"

clean:
	@make -C libft clean
	@echo "\033[33mDestruction des fichier .o libft\t | OK |"

fclean: clean
	@make -C libft fclean
	@echo "\033[33mDestruction du fichier  .a libft\t | OK |"
	@rm -f $(NAME)
	@echo "\033[33mDestruction de l'executable fdf\t\t | OK |"

line:
	@echo "\033[33;32m--------------------------------------"

re: fclean line all

.PHONY: all line fclean clean re
