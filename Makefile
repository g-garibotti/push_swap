# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:32:04 by ggaribot          #+#    #+#              #
#    Updated: 2024/08/09 14:44:31 by ggaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR := srcs
INCDIR := includes
LIBFTDIR := libft

NAME := push_swap

SRC := $(SRCDIR)/push_swap.c $(SRCDIR)/validates.c $(SRCDIR)/init_tab.c

OBJ_DIR = objs
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

CC := cc -g3
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)

LIBFT = $(LIBFTDIR)/libft.a


all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
