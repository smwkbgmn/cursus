/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 13:49:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	set_flag(size_t (*write_flag[7])(va_list *, const char *))
{
	write_flag[0] = &flag_dash;
	write_flag[1] = &flag_hash;
	write_flag[2] = &flag_plus;
	write_flag[3] = &flag_space;
	write_flag[4] = &flag_zero;
	write_flag[5] = &precision;
	write_flag[6] = &width;
}

short	get_flag(char c)
{
	char	flag_set[7];
	short	idx;

	if ('1' <= c && <= '9')
		return (6);
	ft_strlcpy(flag_set, "-#+ 0.", 7);
	idx = 0;
	while (flag_set[idx])
	{
		if (flag_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
