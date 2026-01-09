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

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

SRCS_DIR	= srcs
OBJS_DIR	= objs

# Partie 1 : Libc functions
SRCS_PART1	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			  ft_atoi.c ft_calloc.c ft_strdup.c

# Partie 2 : Additional functions
SRCS_PART2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c

# Bonus : Linked list functions
SRCS_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c

SRCS		= $(SRCS_PART1) $(SRCS_PART2)
SRCS_ALL	= $(SRCS) $(SRCS_BONUS)

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS	= $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))
OBJS_ALL	= $(addprefix $(OBJS_DIR)/, $(SRCS_ALL:.c=.o))

# Header
HEADER		= libft.h

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) created ($(words $(SRCS)) functions)$(NC)"

bonus: $(OBJS) $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)✓ $(NAME) created with bonus ($(words $(SRCS_ALL)) functions)$(NC)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@echo "$(YELLOW)Compiling $<$(NC)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)✗ Object files removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(NC)"

re: fclean all

test: bonus
	@$(CC) $(CFLAGS) -I. main.c -L. -lft -o test_libft
	@echo "$(GREEN)✓ test_libft created$(NC)"
	@./test_libft
	@rm -f test_libft

.PHONY: all bonus clean fclean re test
