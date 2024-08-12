/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:10:53 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 20:37:40 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_push_swap *ps)
{
	int	tmp;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	ps->a->stack[0] = ps->a->stack[1];
	ps->a->stack[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_swap *ps)
{
	int	tmp;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	ps->b->stack[0] = ps->b->stack[1];
	ps->b->stack[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_swap *ps)
{
	sa(ps);
	sb(ps);
	ft_putstr_fd("ss\n", 1);
}
