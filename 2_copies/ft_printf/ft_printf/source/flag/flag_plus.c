/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 17:47:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	check_valid(t_list *head);

short	flag_plus(char *format, t_list *head)
{
	char	*content;

	if (check_valid(head) && format)
	{
		content = ft_strdup("+");
		if (content)
			ft_lstidx(head, 1)->content = content;
		else
			return (FALSE);
	}
	return (TRUE);
}

static short	check_valid(t_list *head)
{
	return (ft_memcmp(ft_lstidx(head, 3)->content, "0", 1) == 0
		|| !ft_lstidx(head, 1)->content);
}
