/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/09/06 16:12:28 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_and_exit_with_message(t_push_swap *ps, char *msg)
{
	if (ps)
	{
		if (ps->a)
		{
			free(ps->a->stack);
			free(ps->a);
		}
		if (ps->b)
		{
			free(ps->b->stack);
			free(ps->b);
		}
		free(ps);
	}
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(0);
}

static void	init_push_swap(t_push_swap **ps)
{
	*ps = malloc(sizeof(t_push_swap));
	if (!*ps)
		free_and_exit_with_message(NULL, "Error\n");
	(*ps)->a = malloc(sizeof(t_stack));
	(*ps)->b = malloc(sizeof(t_stack));
	if (!(*ps)->a || !(*ps)->b)
		free_and_exit_with_message(*ps, "Error\n");
	(*ps)->a->stack = NULL;
	(*ps)->b->stack = NULL;
	(*ps)->a->size = 0;
	(*ps)->b->size = 0;
	(*ps)->a->size_max = 0;
	(*ps)->b->size_max = 0;
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = NULL;
	init_push_swap(&ps);
	validate_arguments_fill_a(argc, argv, ps);
	ps->b->size_max = ps->a->size_max;
	if (!is_sorted(ps->a))
		sort(ps);
	free_and_exit_with_message(ps, NULL);
	return (0);
}
