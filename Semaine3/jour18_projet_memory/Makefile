# Makefile pour Memory Manager

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = memory_manager

SRCS = memory_manager.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ Memory Manager compilé avec succès!"

%.o: %.c memory_manager.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "✓ Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME)
	@echo "✓ Exécutable supprimé"

re: fclean all

test: $(NAME)
	@echo "=== Exécution des tests ==="
	./$(NAME)

valgrind: $(NAME)
	@echo "=== Vérification mémoire avec valgrind ==="
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re test valgrind
