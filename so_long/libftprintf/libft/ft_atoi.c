/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:54:11 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/25 18:04:01 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		negative;
	int		number;

	i = 0;
	negative = 0;
	number = 0;
	while (str[i] < 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = 10 * number + (str[i] - '0');
		i++;
	}
	if (negative % 2 == 1)
		number = number * -1;
	return (number);
}
