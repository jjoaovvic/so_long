/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 05:52:16 by joaovict          #+#    #+#             */
/*   Updated: 2022/06/22 20:07:45 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_list));
	if (new_list != NULL)
	{
		new_list->content = content;
		new_list->next = NULL;
		return (new_list);
	}
	else
		return (NULL);
}
