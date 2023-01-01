/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 10:53:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		(*conversion[8])(va_list *);

	set_spcf(conversion);
	va_start(ptr, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				len += write(1, "%", 1);
			else if (get_spcf(*str) != -1)
				len += conversion[get_spcf(*str)](&ptr);
			else
				len += write(1, str, 1);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ptr);
	return (len);
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
