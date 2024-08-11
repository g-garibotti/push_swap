/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:07:31 by ggaribot          #+#    #+#             */
/*   Updated: 2024/05/23 12:01:22 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_paslaplace(char *result, long int n, long int len)
{
	result[len + 1] = '\0';
	while (n > 0)
	{
		result[len] = (n % 10 + 48);
		n = n / 10;
		len--;
	}
}

static char	*ft_litoa(long n)
{
	long int	len;
	char		*result;

	len = ft_len(n);
	result = malloc((len + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	else
		ft_paslaplace(result, n, len);
	return (result);
}

char	*ft_itoa(int n)
{
	return (ft_litoa(n));
}
