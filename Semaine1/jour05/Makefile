CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
NAME=libft.a

all:$(NAME)
$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all