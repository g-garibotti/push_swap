/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:54:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 19:07:52 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_digits(int argc, char **argv, t_push_swap *ps)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				free_and_exit_with_message(ps, "Error: Invalid argument\n");
			j++;
		}
		i++;
	}
}

static void	check_doubles(long num, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i < ps->a->size)
	{
		if (ps->a->stack[i] == num)
			free_and_exit_with_message(ps, "Error: Duplicates found\n");
		i++;
	}
}

static void	add_num_in_stack(int argc, char **argv, t_push_swap *ps)
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_and_exit_with_message(ps, "Error: Argument out of range\n");
		check_doubles(num, ps);
		ps->a->stack[i] = (int)num;
		ps->a->size++;
		i++;
	}
}

void	validate_arguments_fill_a(int argc, char **argv, t_push_swap *ps)
{
	if (argc < 2)
		free_and_exit_with_message(ps, "Error: No arguments provided\n");
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			free_and_exit_with_message(ps, "Error: Invalid argument\n");
		argc = 0;
		while (argv[argc])
			argc++;
	}
	else
	{
		argv++;
		argc--;
	}
	ps->a->size_max = argc;
	ps->a->stack = malloc(sizeof(int) * ps->a->size_max);
	if (!ps->a->stack)
		free_and_exit_with_message(ps, "Error: Memory allocation failed\n");
	ps->a->size = 0;
	check_digits(argc, argv, ps);
	add_num_in_stack(argc, argv, ps);
}
