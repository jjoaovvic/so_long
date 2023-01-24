/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:49:41 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:31:12 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if ((unsigned char)ch >= 'A' && (unsigned char)ch <= 'Z')
		ch = (unsigned char)ch + 32;
	return (ch);
}
