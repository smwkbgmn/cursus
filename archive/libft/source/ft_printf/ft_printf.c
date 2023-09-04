/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 00:54:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"

static size_t	get_len_format(const char *str);
static int		write_str(const char **str);
static int		write_format(const char **str, va_list *ptr);

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
			apply_len(write_str(&str), &len);
	}
	va_end(ptr);
	return (len);
}

void	apply_len(int in, int *out)
{
	*out = ((*out + in) * (in != ERROR)) - (in == ERROR);
}

static size_t	get_len_format(const char *str)
{
	size_t	idx;

	idx = 1;
	while (get_type_char(str[idx]) == -1)
		idx++;
	return (idx);
}

static int	write_str(const char **str)
{
	int	len;

	len = 0;
	while ((*str)[len] != '%' && (*str)[len])
		len++;
	len = write(1, *str, len);
	if (len != ERROR)
		*str += len;
	return (len);
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
