/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 03:33:29 by donghyu2         ###   ########.fr       */
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
static short	is_formatter(char c);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	writing(str, &ptr, &len);
	va_end(ptr);

	return (len);
}

static void	writing(const char *str, va_list *ptr, int *len)
{
	size_t	len_flag;
	char	*value;

	while (*str && value)
	{
		if (*str == '%')
		{
			// printf("in writing if %%\n");
			str++;
			len_flag = get_len_flag(str);
			// printf("after len_flag\n");
			value = get_value(str, ptr, len_flag);
			// printf("after get_value\n");
			if (value)
			{
				value = apply_flag(str, value, len_flag);
				// printf("after apply_flag\n");
				if (value)
				{
					*len = write(1, value, ft_strlen(value));
					free(value);
					while (is_formatter(*str))
						str++;
				}
			}
		}
		else
			write(1, str++, 1);
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
	while (idx_flag < 5)
	{
		// printf("in apply_flag while 1\n");
		idx = 0;
		while (idx < len_flag)
		{
			// printf("in apply_flag while 2\n");
			if (get_flag(str[idx]) == idx_flag)
			{
				// printf("after compare\n");
				value = flags[idx_flag](str + idx, value);
				// printf("after getting a new value\n");
				if (!value)
					return (0);
				break ;
			}
			else
				idx++;
		}
		idx_flag++;
	}
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

static short	is_formatter(char c)
{
	return (get_spcf(c) >= 0 || get_flag(c) >= 0);
}
