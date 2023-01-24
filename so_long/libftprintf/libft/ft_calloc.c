/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:54:07 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:45:43 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	if (((nitems * size) / size != nitems && size != 0))
		return (NULL);
	pointer = (void *)malloc(nitems * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nitems * size);
	return (pointer);
}
