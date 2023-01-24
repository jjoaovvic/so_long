/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:56:09 by joaovict          #+#    #+#             */
/*   Updated: 2022/09/05 13:45:40 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printeruns(unsigned int n)
{
	if (n > 9)
	{
		ft_printeruns(n / 10);
		ft_printeruns(n % 10);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
	}
}

int	ft_printunsg(unsigned int n)
{
	int	nmb;

	nmb = 0;
	ft_printeruns(n);
	if (n == 0)
		nmb = 1;
	while (n > 0)
	{
		n = n / 10;
		nmb++;
	}
	return (nmb);
}
