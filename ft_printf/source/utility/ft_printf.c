/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 22:27:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

// int	ft_printf(const char *str, ...)
// {
// 	va_list	ptr;
// 	int		len;

// 	size_t (*conversion[9])(va_list *);
// 	set_spcf(conversion);
// 	va_start(ptr, str);
// 	len = 0;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			str++;
// 			if (get_spcf(*str) != -1)
				// len += conversion[get_spcf(*str)](&ptr);
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
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	writing(str, &ptr, &len);
	va_end(ptr);

	return (len);
}

void	writing(const char *str, va_list *ptr, int *len)
{
	int	(*flag[7])(const char *, va_list *);
	int	(*conversion[9])(va_list *);

	set_flag(flag);
	set_spcf(conversion);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (get_flag(*str) > 0)
				flag[get_flag(*str)](str, ptr);
			if (get_flag(*str) == 0)
			{
			}
			conversion[get_spcf(*str)](ptr);
		}
		else
			return ;
	}
}
