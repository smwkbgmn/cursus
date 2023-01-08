/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 15:56:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_len_full_str(t_list *head, short idx_t);

short	flag_width(char *format, t_list *head)
{
	char	*spaces;
	int		width;

	format += pass_flag(format);
	width = ft_atoi(format) - get_len_full_str(head, get_type_str(format));
	if (width > 0)
	{
		spaces = get_str_fill_char(width, ' ');
		if (spaces)
			ft_lstidx(head, 0)->content = spaces;
		else
			return (FALSE);
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
