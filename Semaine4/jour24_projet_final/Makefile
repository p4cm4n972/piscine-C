# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piscine                                     +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 00:00:00 by piscine           #+#    #+#              #
#    Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= mini_editor

SRCS	= main.c mini_editor.c
OBJS	= $(SRCS:.c=.o)
HEADER	= mini_editor.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test.txt

re: fclean all

test: all
	@echo "=== Test du Mini Editor ==="
	@echo "Créons un fichier de test..."
	@echo -e "p\na Hello World\na This is line 2\na Final line\np\nw test.txt\nq" | ./$(NAME)
	@echo ""
	@echo "=== Contenu de test.txt ==="
	@cat test.txt 2>/dev/null || echo "(fichier non créé)"

demo: all
	@echo "Lancez: ./$(NAME) [fichier]"
	@echo "Puis tapez 'h' pour l'aide"

.PHONY: all clean fclean re test demo
