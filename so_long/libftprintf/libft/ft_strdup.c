/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:01:56 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:47:27 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		size;
	int		i;

	size = ft_strlen(src);
	i = 0;
	copy = (char *)malloc ((size + 1) * sizeof(char));
	while (i <= size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
