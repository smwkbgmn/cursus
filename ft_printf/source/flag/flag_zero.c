/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:48 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 22:38:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_len_full_str(t_list *head);

void	flag_zero(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*zeros;
	int		width;

	str += find_flag(str, '0');
	str += pass_flag(str);
	width = ft_atoi(str) - get_len_full_str(*head);
	if (width > 0)
	{
		zeros = get_str_fill_char(width, '0');
		if (zeros)
		{
			node_new = ft_lstnew(zeros);
			if (node_new)
			{
				if (ft_lstsize(*head) == 1)
					ft_lstadd_front(head, node_new);
				else
					ft_lstadd_idx(*head, node_new, 0);
			}
		}
	}
}

static size_t	get_len_full_str(t_list *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		len += ft_strlen(head->content);
		head = head->next;
	}
	return (len);
}
