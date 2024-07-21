/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genarogaribotti <genarogaribotti@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:24:50 by genarogarib       #+#    #+#             */
/*   Updated: 2024/07/14 00:48:03 by genarogarib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_tab(char **tab)
{
	if(check_digits(tab) == 1)
        return (1);
    if(check_int_limits(tab) == 1)
        return (1);
    if(check_double(tab) == 1)
        return (1);
}

int check_digits(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i] != NULL)
    {
        j = 0;
        while (tab[i][j] != '\0')
        {
            if (ft_isdigit(tab[i][j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int check_int_limits(char **tab)
{
    int i;
    int num;

    i = 0;
    while (tab[i] != NULL)
    {
        num = ft_atoi(tab[i]);
        if (num > INT_MAX || (num == 0 && tab[i][0] != '0'))
            return (1);
        i++;
    }
    return (0);
}
