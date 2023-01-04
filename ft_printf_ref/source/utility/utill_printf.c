/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/03 21:03:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libftprintf.h"

static int		writing(const char *str, va_list *ptr);
static size_t	get_len_flag(const char *str);
static int		write_list(t_list *strings, short i_spcf);
static void		free_content(void *content);

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
	t_list	*strings;
	size_t	len_f;
	int		len_w;

	len_w = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len_f = get_len_flag(str);
			strings = get_list(str, ptr, len_f);
			len_w += write_list(strings, find_spcf(str));
			str += len_f;
			ft_lstclear(&strings, &free_content);
		}
		else
			len_w += write(1, str, 1);
		str++;
	}
	return (len_w);
}

static size_t	get_len_flag(const char *str)
{
	size_t	idx;

	idx = 0;
	while (get_flag(*str++) != -1)
		idx++;
	return (idx);
}

static int	write_list(t_list *strings, short i_spcf)
{
	size_t	len_s;
	int		len_w;

	len_w = 0;
	while (strings)
	{
		if (i_spcf == 0 && ft_memcmp(strings->content, "\0", 1) == 0)
			len_s = 1;
		else
			len_s = ft_strlen(strings->content);
		len_w += write(1, strings->content, len_s);
		strings = strings->next;
	}
	return (len_w);
}

static void	free_content(void *content)
{
	if (content)
		free(content);
}
