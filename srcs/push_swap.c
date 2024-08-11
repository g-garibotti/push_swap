/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/11 19:52:28 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_and_exit_with_message(t_push_swap *push_swap, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (push_swap != NULL)
	{
		if (push_swap->a != NULL)
		{
			free(push_swap->a->stack);
			free(push_swap->a);
		}
		if (push_swap->b != NULL)
		{
			free(push_swap->b->stack);
			free(push_swap->b);
		}
		free(push_swap);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			*tab;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!ps)
		free_and_exit_with_message(NULL, "Error main\n");
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->a || !ps->b)
		free_and_exit_with_message(ps, "Error main");
	validate_arguments(argc, argv, ps);
	tab = init_tab(argc, argv, ps);
	if (!tab)
		free_and_exit_with_message(NULL, "Error_main\n");
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d\n", tab[i]);
	}
	free (tab);
	free_and_exit_with_message(ps, NULL);
	//seret
}
