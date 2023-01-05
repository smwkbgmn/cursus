/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/05 13:14:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static short	convert_value(va_list *ptr, t_list *head, short idx_t);
static short	convert_flag(char *format, t_list *head);
static short	*get_switchs(char *format);
static short	check_format(char *format, short idx_f);

short	get_conversion(char *format, t_list *head, va_list *ptr)
{
	convert_value(ptr, head, get_type_str(format));
	convert_flag(format, head);
	return (0);
}

static short	convert_value(va_list *ptr, t_list *head, short idx_t)
{
	short	(*types[9])(va_list *, t_list *head);

	if (idx_t == 8)
		type_percent(head);
	else
	{
		set_type(types);
		types[idx_t](ptr, head);
	}
	return (0);
}

static short	convert_flag(char *format, t_list *head)
{
	short	(*flags[7])(char *, t_list *);
	short	*switchs;
	short	idx_f;

	set_flag(flags);
	switchs = get_switchs(format);
	if (switchs)
	{
		idx_f = 0;
		while (idx_f < 7)
		{
			if (switchs[idx_f])
				flags[idx_f](format, head);
			idx_f++;
		}
		free(switchs);
		return (SUCCESS);
	}
	else
		return (ERROR);
}

static short	*get_switchs(char *format)
{
	short	*switchs;
	short	idx_f;

	switchs = ft_calloc(7, 4);
	if (switchs)
	{
		idx_f = -1;
		while (++idx_f < 7)
		{
			if ((idx_f == 1 || idx_f == 4) && switchs[idx_f - 1] == 1
				&& get_type_str(format) != 8)
				continue ;
			else if ((idx_f == 4 || idx_f == 6) && switchs[5] == 1)
				continue ;
			else if (idx_f == 6 && switchs[4] == 1)
				continue ;
			else
				switchs[idx_f] = check_format(format, idx_f);
		}
	}
	return (switchs);
}

static short	check_format(char *format, short idx_f)
{
	while (*format)
	{
		if (idx_f == 4)
		{
			if (!(get_flag(*format) < 3))
				break ;
		}
		else if (idx_f == 6)
		{
			if (!(get_flag(*format) < 3 || *format == '0'))
				break ;
		}
		else
		{
			if (get_flag(*format) == idx_f)
				break ;
		}
		format++;
	}
	if (get_flag(*format) == idx_f)
		return (1);
	else
		return (0);
}
