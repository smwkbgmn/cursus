/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:04 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	check_type(char *format);
static int		get_width(char *format);
static short	apply_flag(t_list *head, short type, int width, int len_value);
static short	width_and_value_zero(t_list *head, int width);

t_bool	flag_precision(char *format, t_list *head)
{
	int		width;
	int		len_value;

	if (check_type(format))
		return (TRUE);
	width = get_width(format);
	len_value = ft_strlen(ft_lstidx(head, 3)->content);
	return (apply_flag(head, get_type_str(format), width, len_value));
}

static short	check_type(char *format)
{
	short	type;

	type = get_type_str(format);
	return (type == 0 || type == 3 || type == 8);
}

static int	get_width(char *format)
{
	format += find_flag(format, '.');
	format += pass_flag(format, 3);
	return (ft_atoi(format));
}

static short	apply_flag(t_list *head, short type, int width, int len_value)
{
	char	*zeros;

	if (type == 4 && width < len_value)
		ft_bzero(ft_lstidx(head, 3)->content + width, len_value - width);
	else if (type != 4 && width_and_value_zero(head, width))
		ft_bzero(ft_lstidx(head, 3)->content, 1);
	else if (type != 4 && width > len_value)
	{
		zeros = get_str_fill_char(width - len_value, '0');
		if (zeros)
			ft_lstidx(head, 2)->content = zeros;
		else
			return (FALSE);
	}
	return (TRUE);
}

static short	width_and_value_zero(t_list *head, int width)
{
	return (width == 0
		&& ft_memcmp(ft_lstidx(head, 3)->content, "0", 1) == 0);
}
