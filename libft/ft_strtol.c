/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:12:43 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/08 13:49:39 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check_overflow(long result, int digit, int base, int sign)
{
	if (result > (LONG_MAX - digit) / base)
	{
		if (sign == 1)
			return (LONG_MAX);
		return (LONG_MIN);
	}
	return (0);
}

static void	handle_sign(const char **str, int *sign)
{
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long	result;
	int		sign;
	long	overflow;

	result = 0;
	sign = 1;
	handle_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		overflow = check_overflow(result, *str - '0', base, sign);
		if (overflow)
		{
			if (endptr)
				*endptr = (char *)str;
			return (overflow);
		}
		result = result * base + (*str - '0');
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}
