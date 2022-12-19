/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/17 22:58:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	set_flag(int (*flag[7])(const char *, va_list *))
{
	flag[0] = &flag_dash;
	flag[1] = &flag_hash;
	flag[2] = &flag_plus;
	flag[3] = &flag_space;
	flag[4] = &flag_zero;
	flag[5] = &precision;
	flag[6] = &width;
}

short	get_flag(char c)
{
	char	flag[7];
	short	idx;

	if ('1' <= c && c <= '9')
		return (6);
	ft_strlcpy(flag, "-#+ 0.", 7);
	idx = 0;
	while (flag[idx])
	{
		if (flag[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
