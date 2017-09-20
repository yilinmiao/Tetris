NAME = fillit

SRC = *.c

HEADER = *.h


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER) 
	gcc -Wall -Wextra -Werror *.o -o $(NAME)

clean:
	/bin/rm -f *.o *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all