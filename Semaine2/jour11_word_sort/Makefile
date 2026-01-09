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

NAME		= word_sort
NAME_ADV	= word_sort_advanced

SRC			= word_sort.c
SRC_ADV		= word_sort_advanced.c

all: $(NAME) $(NAME_ADV)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME_ADV): $(SRC_ADV)
	$(CC) $(CFLAGS) $(SRC_ADV) -o $(NAME_ADV)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAME_ADV)

re: fclean all

test: all
	@echo "=== Tests word_sort basique ==="
	@./$(NAME) pomme banane cerise
	@echo "Attendu: banane cerise pomme"
	@echo ""
	@./$(NAME) Zorro alice Bob
	@echo "Attendu: Bob Zorro alice"
	@echo ""
	@echo "=== Tests word_sort_advanced ==="
	@echo "-- Test -r (reverse) --"
	@./$(NAME_ADV) -r pomme banane cerise
	@echo "Attendu: pomme cerise banane"
	@echo ""
	@echo "-- Test -i (ignore case) --"
	@./$(NAME_ADV) -i Alice bob CHARLIE
	@echo ""
	@echo "-- Test -n (numeric) --"
	@./$(NAME_ADV) -n 10 2 9 100 1
	@echo "Attendu: 1 2 9 10 100"
	@echo ""
	@echo "-- Test -u (unique) --"
	@./$(NAME_ADV) -u a b a c b
	@echo "Attendu: a b c"
	@echo ""
	@echo "-- Test -rn (combiné) --"
	@./$(NAME_ADV) -rn 10 2 9 100 1
	@echo "Attendu: 100 10 9 2 1"

.PHONY: all clean fclean re test
