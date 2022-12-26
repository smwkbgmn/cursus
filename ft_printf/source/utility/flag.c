/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:12 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 03:19:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	set_flag(char *(*flags[7])(const char *, char *))
{
	flags[0] = &flag_precision;
	flags[1] = &flag_zero;
	flags[2] = &flag_plus;
	flags[3] = &flag_space;
	flags[4] = &flag_hash;
	// flags[5] = &flag_dash;
	// flags[6] = &flag_width;
}

short	get_flag(char c)
{
	char	flag_set[7];
	short	idx;

	if ('1' <= c && c <= '9')
		return (6);
	ft_strlcpy(flag_set, ".0+ #-", 7);
	idx = 0;
	while (flag_set[idx])
	{
		if (flag_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
