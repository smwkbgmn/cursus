/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/16 03:27:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftprintf.h"

static short	convert_value(va_list *ptr, t_list *head, short type);
static short	convert_flag(char *format, t_list *head);
static short	*get_switchs(char *format);
static short	check_format(char *format, short flag);

short	get_conversion(char *format, t_list *head, va_list *ptr)
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

static short	convert_value(va_list *ptr, t_list *head, short type)
{
	short	(*types[9])(va_list *, t_list *head);

	if (type == 8)
		return (type_percent(head));
	else
	{
		set_type(types);
		return (types[type](ptr, head));
	}
}

static short	convert_flag(char *format, t_list *head)
{
	short	(*flags[7])(char *, t_list *);
	short	*switchs;
	short	flag;
	short	valid;

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

static short	*get_switchs(char *format)
{
	short	*switchs;
	short	flag;

	switchs = ft_calloc(7, 4);
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

static short	check_format(char *format, short flag)
{
	while (*format)
	{
		if (flag == 4)
		{
			if (!(get_flag(*format) < 3))
				break ;
		}
		else if (flag == 6)
		{
			if (!(get_flag(*format) < 3 || *format == '0'))
				break ;
		}
		else
		{
			if (get_flag(*format) == flag)
				break ;
		}
		format++;
	}
	if (get_flag(*format) == flag)
		return (TRUE);
	else
		return (FALSE);
}
