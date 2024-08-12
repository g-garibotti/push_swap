/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:52:45 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/12 18:52:52 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *n)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*n <= 13 && *n >= 9) || *n == ' ')
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		result = result * 10 + (*n - '0');
		n++;
	}
	return (sign * result);
}
