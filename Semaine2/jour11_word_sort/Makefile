CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=word_sort.c
OBJ=$(SRC:.c=.o)
NAME=word_sort

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all