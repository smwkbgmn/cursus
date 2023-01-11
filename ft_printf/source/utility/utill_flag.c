/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/11 20:30:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftprintf.h"

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

size_t	pass_flag(char *format, short flag)
{
	size_t	idx;
	char	c;

	idx = 0;
	while (format[idx + 1])
	{
		c = format[idx];
		if (flag == 4 || flag == 6)
		{
			if (get_flag(c) == 6)
				break ;
		}
		else
		{
			if (ft_isdigit(c) || (get_flag(c) != flag && get_flag(c) > 2))
				break ;
		}
		idx++;
	}
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
	char	*str;

	str = ft_calloc(width + 1, 1);
	if (str)
		ft_memset(str, c, width);
	return (str);
}
