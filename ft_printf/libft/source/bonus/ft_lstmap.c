/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/26 01:23:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*malloc_fail(t_list *head, void *content, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*content;

	if (!lst)
		return (0);
	content = f(lst->content);
	head = ft_lstnew(content);
	if (!head)
		return (malloc_fail(head, content, del));
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
			return (malloc_fail(head, content, del));
		ft_lstadd_back(&head, node);
		lst = lst->next;
	}
	return (head);
}

static void	*malloc_fail(t_list *head, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&head, del);
	return (0);
}
