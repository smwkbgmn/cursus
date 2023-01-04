/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:34:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:38:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_del;

	if (del)
	{
		while (*lst)
		{
			node_del = *lst;
			*lst = (*lst)->next;
			del(node_del->content);
			free(node_del);
		}
	}
}
