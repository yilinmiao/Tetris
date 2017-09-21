NAME = fillit

SRC = backtracking.c \
	c_lib.c \
	c_lib2.c \
	free_func.c \
	init_func.c \
	init_shape.c \
	main.c \
	validate.c

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