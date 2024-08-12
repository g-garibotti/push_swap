/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:22:55 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 20:38:09 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->a->stack[i] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap *ps)
{
	int	i;
	int	tmp;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->b->stack[i] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	ft_putstr_fd("rr\n", 1);
}
