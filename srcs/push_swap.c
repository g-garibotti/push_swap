/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:10:59 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 20:58:16 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	tab = init_tab(argc, argv);
	//printf("%s\n", tab[1]);
}
