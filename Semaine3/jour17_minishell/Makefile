# Makefile pour minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = minishell

SRCS = main.c parser.c executor.c builtins.c utils.c signals.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ Minishell compilé avec succès!"

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "✓ Fichiers objets supprimés"

fclean: clean
	rm -f $(NAME)
	@echo "✓ Exécutable supprimé"

re: fclean all

test: $(NAME)
	@echo "=== Tests du minishell ==="
	@echo "Lancez ./minishell et testez :"
	@echo "  - pwd"
	@echo "  - echo Hello World"
	@echo "  - cd /tmp"
	@echo "  - env"
	@echo "  - ls"
	@echo "  - exit"

.PHONY: all clean fclean re test
