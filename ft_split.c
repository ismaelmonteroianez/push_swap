/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:16:47 by ismonter          #+#    #+#             */
/*   Updated: 2026/02/19 17:09:13 by ismonter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
		}
	}
	return (words);
}

static size_t	count_char(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	ft_free(char	**result, size_t pos)
{
	while (pos > 0)
		free(result[--pos]);
	free(result);
}

static char	**set_chars(char const *s, char c, char **result, size_t nwords)
{
	size_t	i;
	size_t	pos;
	size_t	size_words;

	i = 0;
	pos = 0;
	while (pos < nwords)
	{
		while (s[i] == c)
			i++;
		size_words = count_char(&s[i], c);
		result[pos] = malloc(sizeof(char) * (size_words + 1));
		if (result[pos] == NULL)
			return (ft_free(result, pos), NULL);
		ft_strlcpy(result[pos], &s[i], size_words + 1);
		i = i + size_words;
		pos++;
	}
	result[pos] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	nwords;
	char	**result;

	nwords = count_words(s, c);
	result = malloc(sizeof(char *) * (nwords + 1));
	if (result == NULL)
		return (NULL);
	result = set_chars(s, c, result, nwords);
	return (result);
}
