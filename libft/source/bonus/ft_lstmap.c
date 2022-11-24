/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 19:09:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_lstadd_back_int(t_list **lst, t_list *new);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;

	if (!lst)
		return (0);
	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (0);
	lst = lst->next;
	while (lst)
	{
		if (!ft_lstadd_back_int(&new_head, ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		lst = lst->next;
	}
	return (new_head);
}

static int	ft_lstadd_back_int(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (0);
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
	return (1);
}
