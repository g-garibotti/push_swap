/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 16:11:13 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_and_exit_with_message(t_push_swap *push_swap, char *msg)
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
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

static void	init_push_swap(t_push_swap *ps)
{
	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		free_and_exit_with_message(NULL, "Error\n");
	ps->a = malloc(sizeof(t_stack));
	ps->b = malloc(sizeof(t_stack));
	if (!ps->a || !ps->b)
		free_and_exit_with_message(ps, "Error\n");
}

int main(int argc, char **argv)
{
    t_push_swap	*ps;
    //int			*tab;
	int i = 0;

	ps = NULL;
	//tab = NULL;
	init_push_swap(ps);
	validate_arguments(argc, argv, ps);
	while(i < ps->a->size)
	{
		printf("tab[%d] = %d\n", i, ps->a->stack[i]);
		i++;
	}
	return (0);
}
