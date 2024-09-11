/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:54:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/09/11 15:56:46 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**handle_single_argument(char *arg, t_push_swap *ps)
{
	char	**split_argv;

	if (!*arg || is_empty_or_space(arg))
		free_and_exit_with_message(ps, NULL, "Error\n");
	split_argv = ft_split(arg, ' ');
	if (!split_argv)
		free_and_exit_with_message(ps, split_argv, "Error\n");
	return (split_argv);
}

static void	alloc_a_b_mem(t_push_swap *ps, size_t size_max, char **split_argv)
{
	ps->a->size_max = size_max;
	ps->a->stack = malloc(sizeof(int) * ps->a->size_max);
	if (!ps->a->stack)
	{
		if (split_argv)
			free_and_exit_with_message(ps, split_argv, "Error\n");
	}
	ps->a->size = 0;
	ps->b->size_max = size_max;
	ps->b->stack = malloc(sizeof(int) * ps->b->size_max);
	if (!ps->b->stack)
	{
		if (split_argv)
			free_and_exit_with_message(ps, split_argv, "Error\n");
	}
	ps->b->size = 0;
}

static void	add_num_in_stack(int argc, char **argv, t_push_swap *ps,
		char **split_argv)
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_and_exit_with_message(ps, split_argv, "Error\n");
		check_doubles(num, ps);
		ps->a->stack[i] = (int)num;
		ps->a->size++;
		i++;
	}
}

void	validate_arguments_fill_a(int argc, char **argv, t_push_swap *ps)
{
	char	**split_argv;

	split_argv = NULL;
	if (argc < 2)
		free_and_exit_with_message(ps, split_argv, NULL);
	if (argc == 2)
	{
		if (!*argv[1])
			free_and_exit_with_message(ps, NULL, NULL);
		split_argv = handle_single_argument(argv[1], ps);
		argv = split_argv;
		argc = 0;
		while (argv[argc])
			argc++;
	}
	else
	{
		argv++;
		argc--;
	}
	alloc_a_b_mem(ps, argc, split_argv);
	check_digits(argc, argv, ps, split_argv);
	add_num_in_stack(argc, argv, ps, split_argv);
	if (split_argv)
		ft_free_split(split_argv);
}
