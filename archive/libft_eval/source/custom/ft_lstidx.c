/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstidx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:14:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 20:08:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstidx(t_list *head, int idx)
{
	short	size;

	size = ft_lstsize(head);
	if (-1 * size < idx && idx < size)
	{
		idx += size * (idx < 0);
		while (idx-- > 0)
			head = head->next;
	}
	else
		head = NULL;
	return (head);
}
