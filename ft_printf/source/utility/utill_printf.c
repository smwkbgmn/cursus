/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/19 05:34:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Split code
// Find out the reason of TIMEOUT with the type d, i, x and X
// Some adjustment for flag 'space' and 'plus'

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libftprintf.h"

static size_t	get_len(const char *str);
static int		write_format(const char **str, va_list *ptr);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	len_str;
	int		len;

	len = 0;
	va_start(ptr, str);
	apply_len(valid_format(str), &len, 0);
	while (*str && len != ERROR)
	{
		if (*str == '%')
		{
			apply_len(write_format(&str, &ptr), &len, -1);
			apply_len(valid_format(str), &len, 0);
		}
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
	t_list	*list_fm;
	char	*str_fm;
	size_t	len_fm;	
	int		len;

	len = ERROR;
	if (init_list(&list_fm))
	{
		len_fm = get_len_format(*str);
		str_fm = ft_substr(*str, 1, len_fm);
		if (str_fm)
		{
			if (get_conversion(str_fm, list_fm, ptr))
				len = write_list(list_fm, get_type_str(str_fm));
			free(str_fm);
		}
		ft_lstclear(&list_fm, &free_content);
		*str += len_fm + 1;
	}
	return (len);
}
