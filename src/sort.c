/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:09:00 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/13 16:51:14 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	sort_3(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->stack[0];
	b = ps->a->stack[1];
	c = ps->a->stack[2];
	if (a > b && b < c && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && b < c && a > c)
		ra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}

static int	find_min_position(t_stack *stack)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = stack->stack[0];
	pos = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
		{
			min = stack->stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}


static void	push_min_to_b(t_push_swap *ps)
{
	int	pos;

	pos = find_min_position(ps->a);
	if (pos <= ps->a->size / 2)
	{
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
	}
	else
	{
		while (pos < ps->a->size)
		{
			rra(ps);
			pos++;
		}
	}
	pb(ps);
}

static void	sort_4_or_5(t_push_swap *ps)
{
	while (ps->a->size > 3)
		push_min_to_b(ps);
	sort_3(ps);
	while (ps->b->size > 0)
		pa(ps);
}


void	sort(t_push_swap *ps)
{
	if (ps->a->size == 2 && ps->a->stack[0] > ps->a->stack[1])
		sa(ps);
	else if (ps->a->size == 3)
		sort_3(ps);
	else if (ps->a->size <= 5)
		sort_4_or_5(ps);
	else
		sort_big(ps);
}
