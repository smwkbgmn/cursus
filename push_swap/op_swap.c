/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:39:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:03:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *head);

void	sa(t_list *a)
{
	swap(a);
	printf("op_sa\n");
}

void	sb(t_list *b)
{
	swap(b);
	printf("op_sb\n");
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	printf("op_ss\n");
}

void	swap(t_list *head)
{
	void	*tmp;

	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
}
