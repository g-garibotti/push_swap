/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:24:18 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 20:38:06 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[ps->a->size - 1];
	i = ps->a->size - 1;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[i] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[ps->b->size - 1];
	i = ps->b->size - 1;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[i] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
	ft_putstr_fd("rrr\n", 1);
}
