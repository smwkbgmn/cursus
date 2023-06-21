/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

t_bool	type_p(va_list *ptr, t_list *head)
{
	unsigned long	addr;
	char			*str_addr;
	char			*content;

	addr = (unsigned long)va_arg(*ptr, void *);
	str_addr = ft_itoa_ulong_base(addr, "0123456789abcdef");
	if (str_addr)
	{
		content = ft_strjoin("0x", str_addr);
		free(str_addr);
		if (content)
		{
			ft_lstidx(head, 3)->content = content;
			return (TRUE);
		}
	}
	return (FALSE);
}
