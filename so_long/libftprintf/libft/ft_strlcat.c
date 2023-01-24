/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:37:44 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:44:15 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;

	i = 0;
	j = 0;
	dst_size = ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	return (dst_size + ft_strlen(src));
}
