/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:46:18 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/31 18:46:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_idx(t_list *head, t_list *new, int idx)
{
	if (head && new)
	{
		head = ft_lstidx(head, idx);
		new->next = head->next;
		head->next = new;
	}
}
