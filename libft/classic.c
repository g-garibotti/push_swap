/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:07 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 16:51:15 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *str)
{
	int	i;

	if (str == NULL)
	{
		i = 6;
		write(1, "(null)", 6);
		return (i);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_printf(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_printf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_printf("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		count += ft_putchar_printf('-');
	}
	if (n < 10)
	{
		count += ft_putchar_printf(n + 48);
		return (count);
	}
	if (n > 9)
	{
		count += ft_putnbr_printf(n / 10);
		count += ft_putchar_printf((n % 10) + 48);
	}
	return (count);
}

int	ft_putnbr_unsigned_printf(unsigned int n)
{
	int	count;

	count = 0;
	if (n == UINT_MAX)
	{
		count += ft_putstr_printf("4294967295");
		return (10);
	}
	if (n < 10)
	{
		count += ft_putchar_printf(n + '0');
		return (count);
	}
	if (n > 9)
	{
		count += ft_putnbr_unsigned_printf(n / 10);
		count += ft_putchar_printf((n % 10) + 48);
	}
	return (count);
}
