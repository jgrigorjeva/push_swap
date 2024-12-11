CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
SRCS = main.c utils.c  # Source files
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:.c=.o)			# Object files in the root directory
NAME = push_swap			# Output binary (project's name)
LIBFT_DIR = libft			# Directory for libft
LIBFT = $(LIBFT_DIR)/libft.a  # Compiled libft library

# Default target: Build the project
all: $(NAME)

# Build the project binary
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile source files into object files
%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files and binary for the project
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean, including libft library and output binary
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything from scratch
re: fclean all