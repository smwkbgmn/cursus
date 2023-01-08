/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 16:45:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libftprintf.h"

static int		write_format(const char **str, va_list *ptr);
static size_t	get_len_format(const char *str);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, str);
	while (*str && len != ERROR)
	{
		if (*str == '%')
			apply_len(write_format(&str, &ptr), &len);
		else
			apply_len(write(1, str, 1), &len);
		str++;
	}
	va_end(ptr);
	return (len);
}

void	apply_len(int len_in, int *len_out)
{
	*len_out = (*len_out + len_in) * (len_in != ERROR) - (len_in == ERROR);
}

static int	write_format(const char **str, va_list *ptr)
{
	t_list	*list_f;
	char	*str_f;
	size_t	len_f;	
	int		len_w;

	len_w = ERROR;
	if (init_list(&list_f))
	{
		len_f = get_len_format(*str);
		str_f = ft_substr(*str, 1, len_f);
		if (str_f)
		{
			if (get_conversion(str_f, list_f, ptr))
				len_w = write_list(list_f, get_type_str(str_f));
			free(str_f);
		}
		ft_lstclear(&list_f, &free_content);
		*str += len_f;
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
