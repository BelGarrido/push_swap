# Path to ft_printf
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR) 

#------------------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRC= push_swap.c \
	list_utils.c \
	function_utils.c \
	error_related.c \
	stack_related.c \
	swap.c \
	rotate.c \
	reverse_rotate.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

# Server build rule
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