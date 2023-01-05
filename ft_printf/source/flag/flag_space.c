/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 20:23:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	flag_space(char *format, t_list *head)
{
	char	*content;

	format++;
	if (!(ft_lstidx(head, 1)->content))
	{
		content = ft_strdup(" ");
		if (content)
			ft_lstidx(head, 1)->content = content;
		else
			return (ERROR);
	}
	return (SUCCESS);
}
