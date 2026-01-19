# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:49:45 by jdreissi          #+#    #+#              #
#    Updated: 2026/01/19 14:02:28 by jdreissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Iinclude -Wall -Werror -Wextra

HEADER = push_swap.h

SRCS =	srcs/create_stack.c \
		srcs/print_output.c \
		srcs/push_swap_utils.c \
		srcs/push_swap.c \
		srcs/sorting_algorithms.c \
		srcs/swap_functions.c \
		srcs/libft/ft_atoi.c \
		srcs/libft/ft_isdigit.c \
		srcs/libft/ft_split.c \
		srcs/libft/ft_strlen.c \
		srcs/libft/ft_strncmp.c \
		srcs/libft/ft_substr.c

O_FILES = $(SRCS:.c=.o)
		
all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
