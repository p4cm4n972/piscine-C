CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = minigrep

SRCS = minigrep.c search.c options.c colors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
