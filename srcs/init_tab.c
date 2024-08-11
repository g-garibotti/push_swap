/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:43:20 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/11 19:52:32 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**create_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = malloc((argc) * sizeof(char *));
		if (tab == NULL)
			free_and_exit_with_message(NULL, "Error_create_tab_char\n");
		i = 1;
		while (i < argc)
		{
			tab[i - 1] = argv[i];
			i++;
		}
		tab[i - 1] = NULL;
	}
	return (tab);
}

static int	*ft_convert_to_int_tab(int size, char **tab)
{
	int	*int_tab;
	int	i;

	int_tab = (int *)malloc(sizeof(int) * size);
	if (!int_tab)
		free_and_exit_with_message(NULL, "Error\n");
	i = 0;
	while (i < size)
	{
		int_tab[i] = ft_atol(tab[i]);
		i++;
	}
	return (int_tab);
}

int	*init_tab(int argc, char **argv, t_push_swap *ps)
{
	char	**char_tab;
	int		*int_tab;
	int		size;
	int		i;

	char_tab = create_tab(argc, argv);
	if (!char_tab)
		free_and_exit_with_message(ps, "Error_init_tab\n");
	size = 0;
	while (char_tab[size] != NULL)
		size++;
	ps->a->size_max = size;
	ps->b->size_max = size;
	int_tab = ft_convert_to_int_tab(size, char_tab);
	if (argc == 2)
	{
		i = 0;
		while (char_tab[i] != NULL)
		{
			free(char_tab[i]);
			i++;
		}
	free(char_tab);
	}
	return (int_tab);
}
