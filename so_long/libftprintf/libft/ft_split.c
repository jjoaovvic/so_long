/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:20:43 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/26 18:38:39 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_this(char **s, size_t j)
{
	while (j > 0)
	{
		free(s[j - 1]);
		j--;
	}
	free(s);
	return (NULL);
}

static size_t	ft_numb_words(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	is_word;

	words = 0;
	i = 0;
	is_word = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			is_word = 0;
		}
		while (s[i] != c && s[i])
		{
			i++;
			is_word = 1;
		}
		if (is_word == 1)
			words++;
	}
	return (words);
}

static void	ft_malloc_arrays(char const *s, char c, char **matriz)
{
	size_t	i;
	size_t	size_of_word;
	size_t	j;

	i = 0;
	size_of_word = 0;
	j = 0;
	while (s[i])
	{
		size_of_word = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			size_of_word++;
		}
		if (size_of_word > 0)
			matriz[j] = ft_substr(s, i - size_of_word, size_of_word);
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	char	**array_of_words;
	int		freed;

	words = 0;
	i = 0;
	freed = 0;
	if (!s)
		return (NULL);
	words = ft_numb_words(s, c);
	array_of_words = ft_calloc(words + 1, sizeof(char *));
	ft_malloc_arrays(s, c, array_of_words);
	while (i < words && freed == 0)
	{
		if (array_of_words[i] == NULL)
		{
			ft_free_this(array_of_words, words);
			freed = 1;
		}
		i++;
	}
	return (array_of_words);
}
