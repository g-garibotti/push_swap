/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:55:51 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/11 18:46:47 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

//trouver la première occurrence d'un caractère dans une chaîne.
char	*ft_strchr_gnl(const char *s, int c)
{
	c = (char)c;
	while (*s != c && *s != '\0')
		++s;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

//concaténer deux chaînes.
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(sizeof(char) * ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[i + ft_strlen_gnl(s1)] = s2[i];
		i++;
	}
	new_str[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	return (new_str);
}

//dupliquer une chaîne.
char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	int		dup_len;
	int		i;

	dup_len = ft_strlen_gnl(s);
	str = (char *) malloc((dup_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//extraire une sous-chaîne
char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen_gnl(s);
	if (start >= s_len)
		return (ft_strdup_gnl(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
