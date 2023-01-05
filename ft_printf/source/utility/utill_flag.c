/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 21:08:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	set_flag(short (*flags[7])(char *, t_list *))
{
	flags[0] = &flag_plus;
	flags[1] = &flag_space;
	flags[2] = &flag_hash;
	flags[3] = &flag_precision;
	flags[4] = &flag_zero;
	flags[5] = &flag_dash;
	flags[6] = &flag_width;
}

short	get_flag(char c)
{
	char	flag_set[7];
	short	idx;

	if ('1' <= c && c <= '9')
		return (6);
	else
	{
		ft_strlcpy(flag_set, "+ #.0-", 7);
		idx = 0;
		while (flag_set[idx])
		{
			if (flag_set[idx] == c)
				return (idx);
			idx++;
		}
	}
	return (-1);
}

size_t	pass_flag(char *format)
{
	size_t	idx;

	idx = 0;
	while (!ft_isdigit(format[idx]) && format[idx])
		idx++;
	return (idx);
}

size_t	find_flag(char *format, char flag)
{
	size_t	idx;

	idx = 0;
	while (format[idx] != flag)
		idx++;
	return (idx);
}

char	*get_str_fill_char(int width, char c)
{
	char	*format;

	format = malloc(width + 1);
	if (format)
		ft_memset(format, c, width);
	return (format);
}
