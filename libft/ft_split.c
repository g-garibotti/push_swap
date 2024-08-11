/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaribot <ggaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:52 by ggaribot          #+#    #+#             */
/*   Updated: 2024/08/09 19:34:03 by ggaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*create_line(char const **s, char c)
{
	char	*line;
	int		len_words;

	while (**s == c)
		++(*s);
	len_words = word_len(*s, c);
	line = malloc((len_words + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *s, len_words + 1);
	*s += len_words;
	return (line);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;
	char	**output;

	if (s == NULL)
		return (NULL);
	nb_words = count_word(s, c);
	output = malloc((nb_words + 1) * sizeof(char *));
	if (output != NULL)
	{
		i = 0;
		output[nb_words] = NULL;
		while (i < nb_words)
		{
			output[i] = create_line(&s, c);
			if (output[i] == NULL)
			{
				ft_free(output);
				output = NULL;
				break ;
			}
			i++;
		}
	}
	return (output);
}
