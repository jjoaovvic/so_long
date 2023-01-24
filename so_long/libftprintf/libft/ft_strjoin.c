/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:55:37 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:47:37 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	full_size;

	full_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc(full_size + 1, sizeof(char));
	ft_strlcpy(new_str, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, full_size + 1);
	return (new_str);
}
