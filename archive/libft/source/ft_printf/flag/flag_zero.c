/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:48 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:01:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_width(char *format, t_list *head);
static size_t	get_len_full_str(t_list *head, short type);

t_bool	flag_zero(char *format, t_list *head)
{
	char	*zeros;
	int		width;

	width = get_width(format, head);
	if (width > 0)
	{
		zeros = get_str_fill_char(width, '0');
		if (zeros)
			ft_lstidx(head, 2)->content = zeros;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	get_width(char *format, t_list *head)
{
	format += find_flag(format, '0');
	format += pass_flag(format, 4);
	return (ft_atoi(format) - get_len_full_str(head, get_type_str(format)));
}

static size_t	get_len_full_str(t_list *head, short type)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->content)
		{
			if (type_c_with_null(type, head->content))
				len += 1;
			else
				len += ft_strlen(head->content);
		}
		head = head->next;
	}
	return (len);
}
