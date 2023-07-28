/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:38:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*malloc_fail(t_list *head, void *content, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*content;

	head = 0;
	if (lst && f && del)
	{
		while (lst)
		{
			content = f(lst->content);
			node = ft_lstnew(content);
			if (node)
			{
				ft_lstadd_back(&head, node);
				lst = lst->next;
			}
			else
				return (malloc_fail(head, content, del));
		}
	}
	return (head);
}

static void	*malloc_fail(t_list *head, void *content, void (*del)(void *))
{
	del(content);
	if (head)
		ft_lstclear(&head, del);
	return (0);
}
