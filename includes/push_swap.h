/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:00:15 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 19:52:46 by ggaribot         ###   ########.fr       */
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

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

char	**create_tab(int argc, char **argv);
#endif