/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:21:32 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 20:38:03 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_push_swap *ps)
{
	int	i;

	if (ps->b->size == 0)
		return ;
	i = ps->a->size;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[0] = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->a->size++;
	ps->b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_push_swap *ps)
{
	int	i;

	if (ps->a->size == 0)
		return ;
	i = ps->b->size;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[0] = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->b->size++;
	ps->a->size--;
	ft_putstr_fd("pb\n", 1);
}
