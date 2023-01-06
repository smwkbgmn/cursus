/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 12:47:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	check_type(char *format);

short	flag_precision(char *format, t_list *head)
{
	char	*zeros;
	int		width;
	int		len_value;

	if (check_type(format))
		return (SUCCESS);
	len_value = ft_strlen(ft_lstidx(head, 3)->content);
	format += find_flag(format, '.');
	format += pass_flag(format);
	width = ft_atoi(format);
	if (get_type_str(format) == 4 && width < len_value)
		ft_bzero(ft_lstidx(head, 3)->content + width, len_value - width);
	else
	{
		if (width - len_value > 0)
		{
			zeros = get_str_fill_char(width, '0');
			if (zeros)
				ft_lstidx(head, 2)->content = zeros;
			else
				return (ERROR);
		}
	}
	return (SUCCESS);
}

static short	check_type(char *format)
{
	short	idx_t;

	idx_t = get_type_str(format);
	return (idx_t == 0 || idx_t == 3 || idx_t == 8);
}
