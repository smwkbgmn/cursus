/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 13:49:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	set_spcf(size_t (*write_convert[8])(va_list *))
{
	write_convert[0] = &spcf_c;
	write_convert[1] = &spcf_d;
	write_convert[2] = &spcf_i;
	write_convert[3] = &spcf_p;
	write_convert[4] = &spcf_s;
	write_convert[5] = &spcf_u;
	write_convert[6] = &spcf_x_lower;
	write_convert[7] = &spcf_x_upper;
}

short	get_spcf(char c)
{
	char	spcf_set[9];
	short	idx;

	ft_strlcpy(spcf_set, "cdipsuxX", 9);
	idx = 0;
	while (spcf_set[idx])
	{
		if (spcf_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}
