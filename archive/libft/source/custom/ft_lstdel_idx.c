/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:21:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 20:18:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_idx(t_list **head, int idx, void (*del)(void *))
{
	t_list	*node_del;

	node_del = ft_lstidx(*head, idx);
	if (node_del)
	{
		if (idx == 0)
			*head = (*head)->next;
		else
			ft_lstidx(*head, idx - 1)->next = node_del->next;
		ft_lstdelone(node_del, del);
	}
}
