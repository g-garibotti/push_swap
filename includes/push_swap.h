/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:00:15 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/11 19:18:08 by ggaribot         ###   ########.fr       */
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

void	free_and_exit_with_message(t_push_swap *push_swap, char *msg);

//VALIDATES ARGUMENTS
void	validate_arguments(int argc, char **argv, t_push_swap *ps);
long	ft_atol(const char *n);

//CREATE INT TAB
int	*init_tab(int argc, char **argv, t_push_swap *ps);

/*typedef struct s_node
{
	int			nbr; // nombre a trier
	int			index; // position dans la stack
	bool		above_median;
	bool		cheapest;
	t_node		*next; //next node
	t_node		*prev; // prev node
}				t_node;
*/
#endif