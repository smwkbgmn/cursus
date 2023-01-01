/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 02:39:14 by donghyu2         ###   ########.fr       */
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
#include "libft.h"

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#include <stdio.h>

static void		writing(const char *str, va_list *ptr, int *len);
static char		*get_value(const char *str, va_list *ptr, size_t len_flag);
static char		*apply_flag(const char *str, char *value, size_t len_flag);
static size_t	get_len_flag(const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, str);
	writing(str, &ptr, &len);
	va_end(ptr);
	return (len);
}

static void	writing(const char *str, va_list *ptr, int *len)
{
	size_t	len_flag;
	char	*value;
	char	c;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				*len += write(1, "%", 1);
				str++;
			}
			else if (*str == 'c')
			{
				while (get_flag(*str) != -1)
					str++;
				c = va_arg(*ptr, int);
				*len += write(1, &c, 1);
				str++;
			}
			else
			{
				len_flag = get_len_flag(str);
				value = get_value(str, ptr, len_flag);
				if (value)
				{
					value = apply_flag(str, value, len_flag);
					if (value)
					{
						*len += write(1, value, ft_strlen(value));
						free(value);
						while (get_spcf(*str) == -1)
							str++;
						str++;
					}
				}
			}
		}
		else
			*len += write(1, str++, 1);
	}
}

static char	*get_value(const char *str, va_list *ptr, size_t len_flag)
{
	char		*(*specifiers[8])(va_list *);

	set_spcf(specifiers);
	return (specifiers[get_spcf(*(str + len_flag))](ptr));
}

static char	*apply_flag(const char *str, char *value, size_t len_flag)
{
	char	*(*flags[7])(const char *, char *);
	short	idx_flag;
	size_t	idx;

	set_flag(flags);
	idx_flag = 0;
	while (idx_flag < 6)
	{
		idx = 0;
		while (idx < len_flag)
		{
			if (get_flag(str[idx]) == idx_flag)
			{
				value = flags[idx_flag](str + idx, value);
				if (!value)
					return (0);
				break ;
			}
			else
				idx++;
		}
		idx_flag++;
	}
	while (get_flag(*str) != 6 && get_spcf(*str) == -1)
		str++;
	if (ft_isdigit(*str))
		value = flags[6](str, value);
	return (value);
}

static size_t	get_len_flag(const char *str)
{
	size_t	idx;

	idx = 0;
	while (get_flag(*str++) != -1)
		idx++;
	return (idx);
}
