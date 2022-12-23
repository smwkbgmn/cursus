/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/24 04:38:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	set_spcf(char *(*specifiers[8])(va_list *))
{
	specifiers[0] = &spcf_c;
	specifiers[1] = &spcf_d;
	specifiers[2] = &spcf_i;
	specifiers[3] = &spcf_p;
	specifiers[4] = &spcf_s;
	specifiers[5] = &spcf_u;
	specifiers[6] = &spcf_x_lower;
	specifiers[7] = &spcf_x_upper;
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
