/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/05 12:31:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	check_case(const char *format);

short	flag_hash(char *format, t_list *head)
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
			return (ERROR);
	}
	return (SUCCESS);
}

static short	check_case(const char *format)
{
	while (get_type_char(*format) == -1)
		format++;
	return (*format == 'X');
}
