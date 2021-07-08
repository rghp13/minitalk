/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:15:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/01 15:50:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*hold;

	if (!lst)
		return (NULL);
	if (!(head = ft_lstnew((*f)(lst->content))))
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		if (!(hold = ft_lstnew((*f)(tmp->content))))
		{
			ft_lstclear(&head, d);
			return (NULL);
		}
		ft_lstadd_back(&head, hold);
		tmp = tmp->next;
	}
	return (head);
}
