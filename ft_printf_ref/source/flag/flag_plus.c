/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 23:29:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	check_valid(t_list *head);

short	flag_plus(char *format, t_list *head)
{
	char	*content;

	format++;
	if (check_valid(head))
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
