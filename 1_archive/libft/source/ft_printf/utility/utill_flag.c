/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:09:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(t_bool (*flags[7])(char *, t_list *))
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
	short	flag_c;

	idx = 0;
	while (format[idx + 1])
	{
		flag_c = get_flag(format[idx]);
		if (flag == 4 || flag == 6)
		{
			if (flag_c == 6)
				break ;
		}
		else
		{
			if (ft_isdigit(format[idx]) || (flag_c != flag && flag_c > 2))
				break ;
		}
		idx++;
	}
	return (idx);
}

int	find_flag(char *format, char flag)
{
	int	idx;

	idx = 0;
	while (format[idx] != flag && format[idx])
		idx++;
	if (!format[idx])
		return (ERROR);
	else
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
