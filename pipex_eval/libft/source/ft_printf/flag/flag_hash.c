/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	check_case(const char *format);

t_bool	flag_hash(char *format, t_list *head)
{
	char	*content;

	if (ft_memcmp(ft_lstidx(head, 3)->content, "0", 1) == 0)
		content = 0;
	else
	{
		if (check_case(format))
			content = ft_strdup("0X");
		else
			content = ft_strdup("0x");
		if (content)
			ft_lstidx(head, 1)->content = content;
		else
			return (FALSE);
	}
	return (TRUE);
}

static short	check_case(const char *format)
{
	while (get_type_char(*format) == -1)
		format++;
	return (*format == 'X');
}
