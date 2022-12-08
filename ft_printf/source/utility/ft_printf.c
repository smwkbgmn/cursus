/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 13:54:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

// int	ft_printf(const char *str, ...)
// {
// 	va_list	ptr;
// 	int		len;

// 	size_t (*write_convert[9])(va_list *);
// 	set_spcf(write_convert);
// 	va_start(ptr, str);
// 	len = 0;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			str++;
// 			if (get_spcf(*str) != -1)
// 				len += write_convert[get_spcf(*str)](&ptr);
// 			else
// 				len += write(1, str, 1);
// 		}
// 		else
// 			len += write(1, str, 1);
// 		str++;
// 	}
// 	va_end(ptr);
// 	return (len);
// }

int	ft_printf(const char *str, ...)
{
	int		(*write_flag[7])(va_list, const char *str);
	va_list	ptr;
	int		len;

	set_flag(write_flag);
	size_t (*write_convert[8])(va_list *);
	set_spcf(write_convert);
	va_start(ptr, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (get_flag(*str) != -1)
				write_flag[get_flag(*str)](ptr, str);
			if (get_spcf(*str) != -1)
				write_convert[get_spcf(*str)](&ptr);
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
