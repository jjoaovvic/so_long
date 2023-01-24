/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:24:54 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:31:57 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	index;
	char	*new_s;

	size = ft_strlen(s);
	index = 0;
	new_s = ft_calloc(size + 1, sizeof(char));
	while (s[index])
	{
		new_s[index] = f(index, s[index]);
		index++;
	}
	return (new_s);
}
