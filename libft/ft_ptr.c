/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:40:19 by ggaribot          #+#    #+#             */
/*   Updated: 2024/07/12 16:50:09 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_adress_printf(uintptr_t num)
{
	char	*hex_digits;
	char	buffer[17];
	int		count;
	int		i;

	hex_digits = "0123456789abcdef";
	count = 2;
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = hex_digits[num % 16];
			num /= 16;
		}
	}
	buffer[i] = '\0';
	while (i > 0)
	{
		ft_putchar_printf(buffer[--i]);
		count++;
	}
	return (count);
}

int	ft_putnbr_ptr_printf(void *ptr)
{
	uintptr_t	p;

	if (ptr == 0)
		return (ft_putstr_printf("(nil)"));
	p = (uintptr_t)ptr;
	ft_putstr_printf("0x");
	return (putnbr_adress_printf(p));
}
