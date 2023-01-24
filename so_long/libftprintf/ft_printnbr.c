/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:31:45 by joaovict          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:11 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printer(int n)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_printer(147483648);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_printer(-n);
	}
	else if (n > 9)
	{
		ft_printer(n / 10);
		ft_printer(n % 10);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
	}
}

int	ft_printnbr(int n)
{
	int	nmb;

	nmb = 0;
	ft_printer(n);
	if (n == -2147483648)
		nmb = 11;
	else
	{
		if (n <= 0)
		{
			n = n * -1;
			nmb++;
		}
		while (n > 0)
		{
			n = n / 10;
			nmb++;
		}
	}
	return (nmb);
}
