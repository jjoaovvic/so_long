/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:52:19 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/23 18:11:30 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (index < n)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	return (dest);
}
