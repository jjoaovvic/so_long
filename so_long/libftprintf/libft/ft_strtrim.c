/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:26:56 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/26 18:39:03 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		start;
	int		end;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	while (ft_in_set(s1[start], set) == 1)
		start++;
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	trimmed_str = ft_substr(s1, start, end - start);
	return (trimmed_str);
}
