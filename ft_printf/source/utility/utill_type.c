/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/05 12:33:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	set_type(short (*types[8])(va_list *, t_list *))
{
	types[0] = &type_c;
	types[1] = &type_d;
	types[2] = &type_i;
	types[3] = &type_p;
	types[4] = &type_s;
	types[5] = &type_u;
	types[6] = &type_x_lower;
	types[7] = &type_x_upper;
}

short	get_type_char(char c)
{
	char	type_set[10];
	short	idx;

	ft_strlcpy(type_set, "cdipsuxX%", 10);
	idx = 0;
	while (type_set[idx])
	{
		if (type_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

short	get_type_str(char *format)
{
	while (get_type_char(*format) == -1)
		format++;
	return (get_type_char(*format));
}
