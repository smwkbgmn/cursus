/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 15:56:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	flag_plus(char *format, t_list *head)
{
	char	*content;

	format++;
	if (!(ft_lstidx(head, 1)->content))
	{
		content = ft_strdup("+");
		if (content)
			ft_lstidx(head, 1)->content = content;
		else
			return (FALSE);
	}
	return (TRUE);
}
