/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 22:21:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

void	set_flag(void (*flags[7])(const char *, t_list **head))
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

size_t	pass_flag(const char *str)
{
	size_t	idx;

	idx = 0;
	while (!ft_isdigit(str[idx]))
		idx++;
	return (idx);
}

size_t	find_flag(const char *str, char flag)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != flag)
		idx++;
	return (idx);
}

char	*get_str_fill_char(int width, char c)
{
	char	*str;

	str = malloc(width + 1);
	if (str)
		ft_memset(str, c, width);
	return (str);
}
