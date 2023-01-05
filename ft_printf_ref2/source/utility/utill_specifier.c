/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:42:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	set_type(t_list *(*types[8])(va_list *))
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

short	get_type(char c)
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

short	find_type(const char *str)
{
	while (get_type(*str) == -1)
		str++;
	return (get_type(*str));
}

t_list	*check_percent(const char *str)
{
	t_list	*head;
	char	*str_percent;

	head = 0;
	while (get_type(*str) == -1)
		str++;
	if (get_type(*str) == 8)
	{
		str_percent = malloc(2);
		if (str_percent)
		{
			str_percent[0] = '%';
			str_percent[1] = 0;
			head = ft_lstnew(str_percent);
		}
	}
	return (head);
}
