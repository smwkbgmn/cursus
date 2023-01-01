/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 09:49:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_plus(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*value;
	char	*sign;

	str++;
	value = (*head)->content;
	if (*value != '-')
	{
		sign = ft_strdup("+");
		if (sign)
		{
			node_new = ft_lstnew(sign);
			if (node_new)
				ft_lstadd_front(head, node_new);
		}
	}
}
