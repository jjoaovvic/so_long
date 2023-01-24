/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:13:05 by joaovict          #+#    #+#             */
/*   Updated: 2022/09/05 13:47:15 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_realprinterhex(unsigned long int n, char c)
{
	if (n >= 16)
	{
		ft_realprinterhex(n / 16, c);
		ft_realprinterhex(n % 16, c);
	}
	else
	{
		if (n <= 9)
		{
			n = n + '0';
			write(1, &n, 1);
		}
		else
		{
			if (c == 'x')
				ft_printchar(n - 10 + 'a');
			else if (c == 'X')
				ft_printchar(n - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned long n, char c)
{
	int	len;

	len = 0;
	if (n == 0)
	{	
		len = 1;
		write(1, "0", 1);
	}
	else
	{
		ft_realprinterhex(n, c);
		while (n > 0)
		{
			n = n / 16;
			len++;
		}
	}
	return (len);
}
