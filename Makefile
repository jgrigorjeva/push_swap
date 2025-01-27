CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
SRCS = main.c stack_init_end.c stack_init_end2.c checks.c operations.c normalization.c turk_sort.c utils.c \
		sort_small.c sort_three.c print_stacks.c get_oper_count.c get_cheapest.c parse_input.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug:
	@echo "LIBFT = $(LIBFT)"
	@echo "OBJ = $(OBJ)"

.PHONY: all clean fclean re debug
