# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 15:05:03 by jgrigorj          #+#    #+#              #
#    Updated: 2024/11/07 16:08:14 by jgrigorj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files and object files
SRCS = ft_bzero.c ft_isascii.c ft_memcpy.c ft_strchr.c ft_strlen.c \
    	ft_isalnum.c ft_isdigit.c ft_memmove.c ft_strlcat.c ft_tolower.c \
    	ft_isalpha.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_toupper.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS = $(SRCS:.c=.o)

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

# Target library
NAME = libft.a

# Default rule to build the library
all: $(NAME)

# Rule to create the library using the ar command
$(NAME): $(OBJS)
	@echo "Creating static library in root: $(NAME)"
	ar rcs $(NAME) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS) $(BONUS_OBJS)

# Clean up both object files and the library
fclean: clean
	@echo "Cleaning everything (object files and library)..."
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Phony targets
.PHONY: all clean fclean re #bonus