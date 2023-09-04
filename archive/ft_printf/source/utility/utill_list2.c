/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 00:54:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static t_bool	convert_value(va_list *ptr, t_list *head, short type);
static t_bool	convert_flag(char *format, t_list *head);
static t_bool	*get_switchs(char *format);
static t_bool	check_format(char *format, short flag);

t_bool	get_conversion(char *format, t_list *head, va_list *ptr)
{
	if (convert_value(ptr, head, get_type_str(format)))
	{
		if (ft_strlen(format) > 1)
			return (convert_flag(format, head));
		else
			return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	convert_value(va_list *ptr, t_list *head, short type)
{
	t_bool	(*types[9])(va_list *, t_list *head);

	if (type == 8)
		return (type_percent(head));
	else
	{
		set_type(types);
		return (types[type](ptr, head));
	}
}

static t_bool	convert_flag(char *format, t_list *head)
{
	t_bool	(*flags[7])(char *, t_list *);
	t_bool	*switchs;
	short	flag;
	t_bool	valid;

	set_flag(flags);
	switchs = get_switchs(format);
	if (switchs)
	{
		flag = 0;
		valid = TRUE;
		while (flag < 7 && valid)
		{
			if (switchs[flag])
				valid = flags[flag](format, head);
			flag++;
		}
		free(switchs);
		return (valid);
	}
	else
		return (FALSE);
}

static t_bool	*get_switchs(char *format)
{
	t_bool	*switchs;
	short	flag;

	switchs = ft_calloc(7, sizeof(t_bool));
	if (switchs)
	{
		flag = -1;
		while (++flag < 7)
		{
			if ((flag == 1 || flag == 4) && switchs[flag - 1] == TRUE
				&& get_type_str(format) != 8)
				continue ;
			else if ((flag == 4 || flag == 6) && switchs[5] == TRUE)
				continue ;
			else if (flag == 6 && switchs[4] == TRUE)
				continue ;
			else
				switchs[flag] = check_format(format, flag);
		}
	}
	return (switchs);
}

static t_bool	check_format(char *format, short flag)
{
	if (flag == 4)
	{
		while (get_flag(*format) < 3 && *format)
			format++;
	}
	else if (flag == 6)
	{
		while ((get_flag(*format) < 3 || *format == '0') && *format)
			format++;
	}
	else
	{
		while (get_flag(*format) != flag && *format)
			format++;
	}
	return (get_flag(*format) == flag);
}
