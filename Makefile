# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:32:04 by ggaribot          #+#    #+#              #
#    Updated: 2024/08/12 20:56:49 by ggaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
MOVE_DIR = $(SRC_DIR)/movements
OBJ_DIR = objs
INCLUDE_DIR = includes
LIBFT_DIR = libft

# Source files and object files
SRCS = $(SRC_DIR)/push_swap.c $(SRC_DIR)/sort.c $(SRC_DIR)/validates.c \
       $(MOVE_DIR)/swap.c $(MOVE_DIR)/push.c $(MOVE_DIR)/rotate.c $(MOVE_DIR)/reverse_rotate.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Path to the libft library
LIBFT = $(LIBFT_DIR)/libft.a

# Debug information
$(info SRCS = $(SRCS))
$(info OBJS = $(OBJS))

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Rule to compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Attempting to create $@ from $<"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR)/movements/%.o: $(MOVE_DIR)/%.c
	@echo "Attempting to create $@ from $<"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Build the libft library
libft: $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files and library
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Catch-all rule for debugging
%:
	@echo "No rule to make target '$@'"

# Phony targets
.PHONY: all clean fclean re libft