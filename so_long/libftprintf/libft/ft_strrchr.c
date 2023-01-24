/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:08:22 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:33:54 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return ((char *)(str + size));
		size--;
	}
	return (NULL);
}
