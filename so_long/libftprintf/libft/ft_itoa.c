/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:32:41 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/26 18:37:12 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*str_number;
	int		test;
	int		number_size;
	int		negative;

	negative = 0;
	number_size = 1;
	test = n;
	while (test > 9 || test < -9)
	{
		number_size++;
		test = test / 10;
	}
	if (n < 0)
		negative = 1;
	str_number = ft_calloc(number_size + negative + 1, sizeof(char));
	if (n < 0)
		str_number[0] = '-';
	while (number_size > 0)
	{
		str_number[number_size + negative - 1] = (ft_abs(n % 10) + '0');
		number_size--;
		n = n / 10;
	}		
	return (str_number);
}
