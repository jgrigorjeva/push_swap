CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
SRCS = main.c stack_init_end.c operations.c
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
