/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:09:00 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/13 01:04:41 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	sort_3(t_push_swap *ps)
{
	if (ps->a->stack[0] > ps->a->stack[1] && ps->a->stack[0] < ps->a->stack[2])
		sa(ps);
	else if (ps->a->stack[0] > ps->a->stack[1]
		&& ps->a->stack[1] > ps->a->stack[2])
	{
		sa(ps);
		rra(ps);
	}
	else if (ps->a->stack[0] > ps->a->stack[1]
		&& ps->a->stack[1] < ps->a->stack[2])
		ra(ps);
	else if (ps->a->stack[0] < ps->a->stack[1]
		&& ps->a->stack[0] > ps->a->stack[2])
		sa(ps);
	else
		rra(ps);
}

static void	sort_4_or_5(t_push_swap *ps)
{
	int		i;
	int		min;
	int		pos;

	i = 0;
	while (i < 2)
	{
		min = INT_MAX;
		pos = 0;
		i = 0;
		while (i < ps->a->size)
		{
			if (ps->a->stack[i] < min)
			{
				min = ps->a->stack[i];
				pos = i;
			}
			i++;
		}
		if (pos < ps->a->size / 2)
			while (pos-- > 0)
				ra(ps);
		else
			while (pos++ < ps->a->size)
				rra(ps);
		pb(ps);
	}
	sort_3(ps);
	pa(ps);
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
	//else
	//	sort_big(ps);
}

