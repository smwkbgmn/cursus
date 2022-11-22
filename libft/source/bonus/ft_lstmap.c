/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/22 23:41:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_lstnew(void *content);
static int		ft_lstadd_back(t_list **lst, t_list *new);
static void		ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;

	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (0);
	lst = lst->next;
	while (lst)
	{
		if (!ft_lstadd_back(&new_head, ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		lst = lst->next;
	}
	return (new_head);
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

static int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (0);
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
	return (1);
}

static void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		del(prev->content);
		free(prev);
	}
}