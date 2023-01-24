/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:40:26 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:47:49 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	i;
	char	*s_cpy;

	size = ft_strlen(s);
	i = 0;
	s_cpy = s;
	while (i < size)
	{
		f(i, s_cpy);
		s_cpy++;
		i++;
	}
}
