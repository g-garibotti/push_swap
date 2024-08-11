/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:12:00 by ggaribot          #+#    #+#             */
/*   Updated: 2024/05/23 14:59:59 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charset(char c, char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charset(s1[start], set) == 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charset(s1[end - 1], set) == 0)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}

/*char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	s1_len;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_charset(s1[start], set) == 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charset(s1[end - 1], set) == 0)
		end--;
	len = end - start;
	s1_len = ft_strlen(s1);
	str = malloc(sizeof(char) * (s1_len + 1 - start - (s1_len - end)) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_substr(s1, start, len);
	return (str);
}*/
