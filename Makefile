# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 21:47:49 by ymiao             #+#    #+#              #
#    Updated: 2017/09/21 21:47:50 by ymiao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	list_generator.c \
	map_generator.c \
	tetris_generator.c \
	map_preparation.c \
	validation.c \
	map_cleaner.c \
	c_lib.c

HEADER = fillit.h


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	gcc -Wall -Wextra -Werror *.o -o $(NAME)


clean:
	/bin/rm -f *.o *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
