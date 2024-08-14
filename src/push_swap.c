/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/14 17:42:47 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_putstr_fd(msg, 1);
	exit(0);
}

static void	init_push_swap(t_push_swap **ps)
{
	*ps = malloc(sizeof(t_push_swap));
	if (!*ps)
		free_and_exit_with_message(NULL, "Error: Failed to allocate ps\n");

	(*ps)->a = malloc(sizeof(t_stack));
	(*ps)->b = malloc(sizeof(t_stack));
	if (!(*ps)->a || !(*ps)->b)
		free_and_exit_with_message(*ps, "Error: Failed to allocate stacks\n");

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

	
	int i = 0;
	while (i < ps->a->size)
	{
		printf("stack_a[%d] = %d\n", i, ps->a->stack[i]);
		i++;
	}
	sort(ps);
	printf("After sort:\n");
	i = 0;
	while (i < ps->a->size)
	{
		printf("stack_a[%d] = %d\n", i, ps->a->stack[i]);
		i++;
	}
	free_and_exit_with_message(ps, "OK\n");
	return (0);
}
