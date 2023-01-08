/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:48 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 15:55:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_len_full_str(t_list *head, short idx_t);

short	flag_zero(char *format, t_list *head)
{
	char	*zeros;
	int		width;

	format += find_flag(format, '0');
	format += pass_flag(format);
	width = ft_atoi(format) - get_len_full_str(head, get_type_str(format));
	if (width > 0)
	{
		zeros = get_str_fill_char(width, '0');
		if (zeros)
			ft_lstidx(head, 2)->content = zeros;
	}
	return (TRUE);
}

static size_t	get_len_full_str(t_list *head, short idx_t)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->content)
		{
			if (idx_t == 0 && ft_memcmp(head->content, "\0", 1) == 0)
				len += 1;
			else
				len += ft_strlen(head->content);
		}
		head = head->next;
	}
	return (len);
}
