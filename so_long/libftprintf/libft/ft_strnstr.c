/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:37:15 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:48:04 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!big || !little)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		k = i;
		while (big[k] == little[j] && k < len)
		{
			j++;
			k++;
			if (little[j] == '\0')
				return ((char *)big + k - j);
		}			
		j = 0;
		i++;
	}
	return (NULL);
}
