/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	writing(str, &ptr, &len);
	va_end(ptr);

	return (len);
}

void	writing(const char *str, va_list *ptr, int *len)
{
	char	*converted;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			converted = apply_flag(str, get_conversion(str, ptr));
			write(1, converted, ft_strlen(converted));
			free(converted);
			while (is_formatter == 1)
				str++;
		}
		else
			write(1, str++, 1);
	}
}

static char	*get_conversion(const char *str, va_list *ptr)
{
	int		(*conversion[8])(va_list *);

	set_spcf(conversion);
	while (get_flag(*str) >= 0)
		str++;
	return (conversion[get_spcf(*str)](ptr));
}

static char	*apply_flag(const char *str, char *converted)
{
	while (*str && *str != '%')
	{		
	}	
}

static short	is_formatter(char c)
{
	return (get_spcf(c) >= 0 || get_flag(c) >= 0);
}

// [1 ~ 9] just number or number with [0], [-]
// pad N space (just number) / N space with left align (-) / N zero (0) 

// [+] plus sign
// add preceeding '+' charater to positive number

// [ ] space
// pad 1 space for align to positive number

// [#] hash with [x] or [X]
// add preceeding '0x' or '0X' character

// [.] [1 ~ 9] precision 
// with specifier d, i it fills the space with zero
