/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:52:05 by ggaribot          #+#    #+#             */
/*   Updated: 2024/09/06 16:13:04 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = stack->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_push_swap *ps)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;

	max_bits = get_max_bits(ps->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < ps->a->size_max)
		{
			num = ps->a->stack[0];
			if ((num >> i) & 1)
				ra(ps);
			else
				pb(ps);
			j++;
		}
		while (ps->b->size > 0)
			pa(ps);
		i++;
	}
}
