/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:43:43 by ggaribot          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:11 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_digits(int argc, char **argv, t_push_swap *ps, char **split_argv)
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
				free_and_exit_with_message(ps, split_argv, "Error\n");
			has_digit = 1;
			j++;
		}
		if (!has_digit)
			free_and_exit_with_message(ps, split_argv, "Error\n");
		i++;
	}
}

void	check_doubles(long num, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i < ps->a->size)
	{
		if (ps->a->stack[i] == num)
			free_and_exit_with_message(ps, NULL, "Error\n");
		i++;
	}
}

int	is_empty_or_space(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}
