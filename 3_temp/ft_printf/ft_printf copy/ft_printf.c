/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 16:23:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"

static size_t	get_len(const char *str);
static int		write_format(const char **str, va_list *ptr);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	len_str;
	int		len;

	len = 0;
	va_start(ptr, str);
	while (*str && len != ERROR)
	{
		if (*str == '%')
			apply_len(write_format(&str, &ptr), &len, -1);
		else
		{
			len_str = get_len(str);
			apply_len(write(1, str, len_str), &len, -1);
			str += len_str;
		}
	}
	va_end(ptr);
	return (len);
}

void	apply_len(int in, int *out, short flag)
{
	*out = (*out + in * (flag == ERROR))
		* (in != flag)
		- (in == flag);
}

size_t	get_len_format(const char *str)
{
	size_t	idx;

	idx = 1;
	while (get_type_char(str[idx]) == -1)
		idx++;
	return (idx);
}

static size_t	get_len(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '%' && str[idx])
		idx++;
	return (idx);
}

static int	write_format(const char **str, va_list *ptr)
{
	t_list	*list_f;
	char	*str_f;
	size_t	len_f;	
	int		len;

	len = ERROR;
	if (init_list(&list_f))
	{
		len_f = get_len_format(*str);
		str_f = ft_substr(*str, 1, len_f);
		if (str_f)
		{
			if (get_conversion(str_f, list_f, ptr))
				len = write_list(list_f, get_type_str(str_f));
			free(str_f);
		}
		ft_lstclear(&list_f, &free_content);
		*str += len_f + 1;
	}
	return (len);
}
