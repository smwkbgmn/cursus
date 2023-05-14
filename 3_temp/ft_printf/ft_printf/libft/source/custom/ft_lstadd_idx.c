/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:46:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 14:41:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_idx(t_list **head, t_list *new, int idx)
{
	t_list	*node_prev;
	int		size;

	size = ft_lstsize(*head);
	if (idx == 0)
		ft_lstadd_front(head, new);
	else if (idx == size || idx == -1)
		ft_lstadd_back(head, new);
	else
	{
		node_prev = ft_lstidx(*head, idx - 1);
		if (node_prev)
		{
			new->next = node_prev->next;
			node_prev->next = new;
		}
	}
}
