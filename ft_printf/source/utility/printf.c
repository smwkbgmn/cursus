/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 20:29:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// [1 ~ 9] just number or number with [0], [-]
// pad N space (just number) / N space with left align (-) / N zero (0) 

// [+] plus sign
// add preceeding '+' charater to positive number

// [ ] space
// pad 1 space for align to positive number

// [#] hash with [x] or [X]
// add preceeding '0x' or '0X' character

// [.] [1 ~ 9] precision 
// with specifiers d, i it fills the space with zero

// ### To do ###
// Check validation of a format string

// These flags may not use together 
// '-' and '0'
// '.' and '0'
// '+' and ' '
// '#' and '+', '-', ' ' 

// Handle INT_MAX overflow at the width flags

#include "libftprintf.h"

#include <stdlib.h>
#include <unistd.h>

static int		writing(const char *str, va_list *ptr);
static size_t	get_len_flag(const char *str);
static int		write_list(t_list *strings);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	len = writing(str, &ptr);
	va_end(ptr);
	return (len);
}

static int	writing(const char *str, va_list *ptr)
{
	t_list	*strings;
	size_t	l_flag;
	int		l_print;
	int		valid;

	l_print = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			l_flag = get_len_flag(str);
			strings = get_list(str, ptr, l_flag);
			if (strings)
			{
				valid = write_list(strings);
				if (valid != -1)
					l_print += valid;
			}
			str += l_flag;
		}
		else
			l_print += write(1, str, 1);
		str++;
	}
	return (l_print);
}

static size_t	get_len_flag(const char *str)
{
	size_t	idx;

	idx = 0;
	while (get_flag(*str++) != -1)
		idx++;
	return (idx);
}

static int	write_list(t_list *strings)
{
	size_t	l_str;
	int		l_print;

	l_print = 0;
	while (strings)
	{
		l_str = ft_strlen(strings->content);
		l_print += write(1, strings->content, l_str);
		strings = strings->next;
	}
	return (l_print);
}
