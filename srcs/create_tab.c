/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genarogaribotti <genarogaribotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:50:26 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/13 17:50:51 by genarogarib      ###   ########.fr       */
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

char	**init_tab(int argc, char **argv)
{
	char	**char_tab;

	char_tab = create_tab(argc, argv);
	if (check_tab(char_tab) == 1)
		return (NULL);
}