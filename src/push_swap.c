/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/13 19:06:35 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_push_swap(t_push_swap *push_swap)
{
	if (push_swap)
	{
		if (push_swap->a)
		{
			if (push_swap->a->stack)
				free(push_swap->a->stack);
			free(push_swap->a);
		}
		if (push_swap->b)
		{
			if (push_swap->b->stack)
				free(push_swap->b->stack);
			free(push_swap->b);
		}
		free(push_swap);
	}
}

void	free_and_exit_with_message(t_push_swap *push_swap, char *msg)
{
	free_push_swap(push_swap);
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

static void	init_push_swap(t_push_swap **ps)
{
	*ps = malloc(sizeof(t_push_swap));
	if (!*ps)
		free_and_exit_with_message(NULL, "Error: Failed allocate push_swap\n");
	(*ps)->a = malloc(sizeof(t_stack));
	(*ps)->b = malloc(sizeof(t_stack));
	if (!(*ps)->a || !(*ps)->b)
		free_and_exit_with_message(*ps, "Error: Failed to allocate stacks\n");
	(*ps)->a->stack = malloc(sizeof(int) * 10);
	(*ps)->b->stack = malloc(sizeof(int) * 10);
	if (!(*ps)->a->stack || !(*ps)->b->stack)
		free_and_exit_with_message(*ps, "Error: Failed to allocate stack\n");

	(*ps)->a->size = 0;
	(*ps)->b->size = 0;
	(*ps)->a->size_max = 10;
	(*ps)->b->size_max = 10;
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
	free_push_swap(ps);
	printf("OK\n");
	return (0);
}
