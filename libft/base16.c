/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:39:18 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 16:51:17 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_converthexa_printf(unsigned long num, char c)
{
	int		i;
	int		output;
	char	toprint[17];

	i = 0;
	if (num == 0)
		return (ft_putchar_printf('0'));
	while (num > 0)
	{
		if (num % 16 <= 9)
			toprint[i] = num % 16 + '0';
		else
			toprint[i] = num % 16 + c - 10;
		num = num / 16;
		i++;
	}
	toprint[i] = '\0';
	output = ft_putrstr_printf(toprint);
	return (output);
}

int	ft_base16low_printf(unsigned long num)
{
	return (ft_converthexa_printf(num, 'a'));
}

int	ft_base16high_printf(unsigned long num)
{
	return (ft_converthexa_printf(num, 'A'));
}

int	ft_putrstr_printf(char *str)
{
	int	i;
	int	output;

	if (str == NULL)
		return (ft_putstr_printf("(null)"));
	i = 0;
	while (str[i] != '\0')
		i++;
	output = i;
	i--;
	while (i >= 0)
	{
		ft_putchar_printf(str[i]);
		i--;
	}
	return (output);
}
