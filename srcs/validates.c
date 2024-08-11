/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:54:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/11 19:52:30 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((res * sign));
}

static void	validate_isdigit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_and_exit_with_message(NULL, "Error_isdigit\n");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error_isdigit\n");
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
					&& argv[i][j] != '-' && argv[i][j] != '+')
				free_and_exit_with_message(NULL, "Error_isdigit\n");
			if ((argv[i][j] == '-' || argv[i][j] == '+')
					&& ((j > 0 && argv[i][j - 1] != ' ')
					|| !ft_isdigit(argv[i][j + 1])))
				free_and_exit_with_message(NULL, "Error_isdigit\n");
		j++;
		}
	}
}

static void	validate_check_duplicates(int argc, char **argv, t_push_swap *ps)
{
	long	*values;
	int		i;
	int		j;
	long	num;

	values = (long *)malloc(sizeof(long) * (argc - 1));
	if (!values)
		free_and_exit_with_message(ps, "Error_duplicates\n");
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		j = 0;
		while (j < i - 1)
		{
			if (values[j] == num)
			{
				free(values);
				free_and_exit_with_message(ps, "Error_duplicates\n");
			}
			j++;
		}
		values[i++ - 1] = num;
	}
	free(values);
}

void	validate_arguments(int argc, char **argv, t_push_swap *ps)
{
	validate_isdigit(argc, argv);
	validate_check_duplicates(argc, argv, ps);
}
