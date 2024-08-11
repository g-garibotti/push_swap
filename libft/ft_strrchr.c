/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:44:05 by genarogarib       #+#    #+#             */
/*   Updated: 2024/05/23 14:42:36 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occu;

	c = (unsigned char)c;
	last_occu = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_occu = (char *)s;
		++s;
	}
	if (c == '\0')
		last_occu = (char *)s;
	return (last_occu);
}
