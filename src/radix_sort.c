/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:52:05 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/14 18:10:56 by ggaribot         ###   ########.fr       */
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

	max_bits = get_max_bits(ps->a); // Get the maximum number of bits needed
	i = 0;
	while (i < max_bits)            // Iterate over each bit
	{
		j = 0;
		while (j < ps->a->size_max) // Process all elements in stack A
		{
			num = ps->a->stack[0];
			if ((num >> i) & 1)     // Check the ith bit
				ra(ps);             // Rotate A if the bit is 1
			else
				pb(ps);             // Push to B if the bit is 0
			j++;
		}
		while (ps->b->size > 0)     // Push everything back to A from B
			pa(ps);
		i++;
	}
}
