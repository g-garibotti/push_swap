/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genarogaribotti <genarogaribotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:00:15 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/13 16:42:22 by genarogarib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node {
    int             nbr;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

t_node  *new_node(int value);
void    push(t_node **pile, int value);
void    print_stack(t_node *pile);

#endif