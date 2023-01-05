/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:34:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_space(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*value;
	char	*sign;

	str++;
	value = (*head)->content;
	if (*value != '-')
	{
		sign = ft_strdup(" ");
		if (sign)
		{
			node_new = ft_lstnew(sign);
			if (node_new)
				ft_lstadd_front(head, node_new);
		}
	}
}
