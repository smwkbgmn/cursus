/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/05 13:09:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <unistd.h>

static int		writing(const char *str, va_list *ptr);
static size_t	get_len_format(const char *str);

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
	t_list	*list_format;
	char	*str_format;
	size_t	len_f;
	int		len_w;

	init_list(&list_format);
	len_w = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len_f = get_len_format(str);
			str_format = ft_substr(str, 1, len_f);
			get_conversion(str_format, list_format, ptr);
			len_w += write_list(list_format, get_type_str(str_format));
			str += len_f;
			free(str_format);
			ft_lstclear(&list_format, &free_content);
		}
		else
			len_w += write(1, str, 1);
		str++;
	}
	return (len_w);
}

static size_t	get_len_format(const char *str)
{
	size_t	idx;

	idx = 1;
	while (get_type_char(str[idx]) == -1)
		idx++;
	return (idx);
}
