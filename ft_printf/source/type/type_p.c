/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 17:28:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	type_p(va_list *ptr, t_list *head)
{
	char	*content;

	content = ft_itoa_address((unsigned long)va_arg(*ptr, void *));
	if (content)
	{
		ft_lstidx(head, 3)->content = content;
		return (SUCCESS);
	}
	else
		return (ERROR);
}
