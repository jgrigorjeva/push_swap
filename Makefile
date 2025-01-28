CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
COMMON_SRCS = stack_init_end.c stack_init_end2.c checks.c operations.c normalization.c turk_sort.c utils.c \
              sort_small.c sort_three.c print_stacks.c get_oper_count.c get_cheapest.c parse_input.c \
			  error.c
PUSH_SWAP_SRCS = main.c
CHECKER_SRCS = checker.c checker_utils.c

COMMON_SRC = $(addprefix $(SRC_DIR), $(COMMON_SRCS))
PUSH_SWAP_SRC = $(addprefix $(SRC_DIR), $(PUSH_SWAP_SRCS))
CHECKER_SRC = $(addprefix $(SRC_DIR), $(CHECKER_SRCS))

COMMON_OBJ = $(COMMON_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

NAME = push_swap
CHECKER = checker

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default target
all: $(NAME)

# Build the push_swap program
$(NAME): $(LIBFT) $(COMMON_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT) -o $(NAME)

# Build the checker program (bonus target)
bonus: $(LIBFT) $(COMMON_OBJ) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJ) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)

# Rule to compile .o files from .c files
%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(COMMON_OBJ) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean all build artifacts
fclean: clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Debug target to print variables
debug:
	@echo "COMMON_OBJ = $(COMMON_OBJ)"
	@echo "PUSH_SWAP_OBJ = $(PUSH_SWAP_OBJ)"
	@echo "CHECKER_OBJ = $(CHECKER_OBJ)"
	@echo "LIBFT = $(LIBFT)"

.PHONY: all clean fclean re debug bonus