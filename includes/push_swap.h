/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:00:15 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 19:06:00 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		size_max;

}				t_stack;

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
}				t_push_swap;

//PUSH_SWAP.c
void	free_and_exit_with_message(t_push_swap *push_swap, char *msg);

//VALIDATES.c
void	validate_arguments_fill_a(int argc, char **argv, t_push_swap *ps);

#endif