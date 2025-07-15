# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 11:26:48 by anagarri@st       #+#    #+#              #
#    Updated: 2025/07/15 13:24:04 by anagarri@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Path to ft_printf
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR) 

#------------------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRC= push_swap.c \
	utils.c \
	utils2.c \
	error_related.c \
	stack_related.c \
	stack_related2.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	sort.c \
	free.c \
	costs.c \
	costs_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re