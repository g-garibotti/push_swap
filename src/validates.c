/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:54:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/13 00:53:11 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_digits(int argc, char **argv, t_push_swap *ps)
{
	int	i;
	int	j;
	int	has_digit;

	i = 0;
	while (i < argc)
	{
		j = 0;
		has_digit = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				free_and_exit_with_message(ps, "Error: Invalid argument\n");
			has_digit = 1;
			j++;
		}
		if (!has_digit)
			free_and_exit_with_message(ps, "Error: Empty argument\n");
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

static int	is_empty_or_space(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

void	validate_arguments_fill_a(int argc, char **argv, t_push_swap *ps)
{
	if (argc < 2)
		free_and_exit_with_message(ps, "Error: No arguments provided\n");
	if (argc == 2)
	{
		if (!*argv[1] || is_empty_or_space(argv[1]))
			free_and_exit_with_message(ps, "Error: Empty argument\n");
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
