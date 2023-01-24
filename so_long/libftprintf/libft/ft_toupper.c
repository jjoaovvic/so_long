/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:44:15 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/17 00:34:06 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	if ((unsigned char)ch >= 'a' && (unsigned char)ch <= 'z')
		ch = (unsigned char)ch - 32;
	return (ch);
}
