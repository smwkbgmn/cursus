/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:35:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	check_type(const char *str);

void	flag_precision(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*zeros;
	int		width;
	int		l_str;
	char 	*casted;

	if (!check_type(str))
		return ;
	l_str = ft_strlen(ft_lstlast(*head)->content);
	str += find_flag(str, '.');
	str += pass_flag(str);
	if (find_type(str) == 4)
	{
		width = ft_atoi(str);
		if (width < l_str)
		{
			casted = (char *)(ft_lstlast(*head)->content);
			casted[width] = 0;
		}
	}
	else
	{
		width = ft_atoi(str) - l_str;
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
}

static short	check_type(const char *str)
{
	short	idx_t;

	idx_t = find_type(str);
	return (idx_t != 0 && idx_t != 3 && idx_t != 8);
}
