/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:50:26 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 20:58:14 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**create_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 1;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = malloc((argc - 1) * sizeof(char *));
		if (tab == NULL)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			tab[i - 1] = argv[i];
			i++;
		}
	}
	return (tab);
}

int	check_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j])
		}
	}
}

char	**init_tab(int argc, char **argv)
{
	char	**tab;

	tab = create_tab(argc, argv);
	if (check_tab(tab) == 1)
		return (1);

}