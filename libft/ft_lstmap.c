/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 23:28:54 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/08/26 03:10:19 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	tmp = new;
	while ((lst = lst->next))
	{
		if (!(tmp->next = ft_lstnew((f)(lst->content))))
			ft_lstclear(&new, del);
		tmp = tmp->next;
	}
	return (new);
}
