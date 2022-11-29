/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:33:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 23:12:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

static void		set_spcf(void (*spcf_function[9])(va_list *));
static short	get_spcf(char spcf);

void	writing(const char *str, va_list *ptr)
{
	void	(*spcf_function[9])(va_list *);

	set_spcf(spcf_function);
	while (*str)
	{
		if (*str == '%' && get_spcf(*(str + 1)) != -1)
		{
			str++;
			spcf_function[get_spcf(*str)](ptr);
		}
		else
			write(1, str, 1);
		str++;
	}
}

static void	set_spcf(void (*spcf_function[9])(va_list *))
{
	spcf_function[0] = &spcf_c;
	spcf_function[1] = &spcf_d;
	spcf_function[2] = &spcf_i;
	spcf_function[3] = &spcf_p;
	spcf_function[4] = &spcf_s;
	spcf_function[5] = &spcf_u;
	spcf_function[6] = &spcf_x_lower;
	spcf_function[7] = &spcf_x_upper;
}

static short	get_spcf(char spcf)
{
	char	spcf_set[10];
	short	idx;

	ft_strlcpy(spcf_set, "cdipsuxX", 9);

	idx = 0;
	while (spcf_set[idx] != spcf && spcf_set[idx])
		idx++;
	if (spcf_set[idx] == 0)
		return (-1);
	else
		return (idx);
}
