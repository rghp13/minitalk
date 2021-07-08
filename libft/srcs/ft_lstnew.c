/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:34:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/28 15:03:52 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	if (!(ptr = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->next = NULL;
	}
	else
	{
		ptr->content = content;
		ptr->next = NULL;
	}
	return (ptr);
}
