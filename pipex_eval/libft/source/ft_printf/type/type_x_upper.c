/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	type_x_upper(va_list *ptr, t_list *head)
{
	unsigned int	dec;
	char			*hex;

	dec = va_arg(*ptr, unsigned int);
	hex = ft_itoa_uint_base(dec, "0123456789ABCDEF");
	if (hex)
	{
		ft_lstidx(head, 3)->content = hex;
		return (TRUE);
	}
	else
		return (FALSE);
}
