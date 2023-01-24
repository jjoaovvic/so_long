/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:53:20 by joaovict          #+#    #+#             */
/*   Updated: 2022/09/05 18:49:26 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_sorter(int c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printpnt(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printunsg(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_printchar('%'));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		nmb_of_chars;
	int		i;

	nmb_of_chars = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			nmb_of_chars += flag_sorter(str[i], args);
		}
		else
			nmb_of_chars += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (nmb_of_chars);
}
