/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:32:33 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/23 18:21:51 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*cpy;

	temp = *lst;
	while (temp)
	{
		cpy = temp->next;
		del(temp->content);
		free(temp);
		temp = cpy;
	}
	*lst = NULL;
}
