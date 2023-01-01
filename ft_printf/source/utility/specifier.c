/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 07:37:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_spcf(t_list *(*specifiers[7])(va_list *))
{
	specifiers[0] = &spcf_d;
	specifiers[1] = &spcf_i;
	specifiers[2] = &spcf_p;
	specifiers[3] = &spcf_s;
	specifiers[4] = &spcf_u;
	specifiers[5] = &spcf_x_lower;
	specifiers[6] = &spcf_x_upper;
}

short	get_spcf(char c)
{
	char	spcf_set[8];
	short	idx;

	ft_strlcpy(spcf_set, "dipsuxX", 8);
	idx = 0;
	while (spcf_set[idx])
	{
		if (spcf_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
