/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:54:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 16:16:07 by ggaribot         ###   ########.fr       */
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
		if (argv[i][j] == '-')
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

long	ft_atol(const char *n)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*n <= 13 && *n >= 9) || *n == ' ')
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		result = result * 10 + (*n - '0');
		n++;
	}
	return (sign * result);
}
static void	check_doubles(long num, t_push_swap *ps)
{
	int i;

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
	int i;
	long num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_and_exit_with_message(ps, "Error: Argument out of range\n");
		check_doubles(num, ps);
		ps->a->stack[i - 1] = (int)num;
		ps->a->size++;
		i++;
	}
}

void	validate_arguments(int argc, char **argv, t_push_swap *ps)
{
	char	**splited_argv;

	splited_argv = NULL;
	if (argc < 2)
		free_and_exit_with_message(ps, "Error: No arguments provided\n");
	if (argc == 2)
	{
		splited_argv = ft_split(argv[1], ' ');
		if (!splited_argv)
			free_and_exit_with_message(ps, "Error: Invalid argument\n");
		argv = splited_argv;
		argc = 0;
		while (argv[argc])
			argc++;
	}
		check_digits(argc, argv, ps);
		add_num_in_stack(argc, argv, ps);
}
