/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 22:38:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_precision(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*zeros;
	int		width;

	str += find_flag(str, '.');
	str += pass_flag(str);
	width = ft_atoi(str) - ft_strlen(ft_lstlast(*head)->content);
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
