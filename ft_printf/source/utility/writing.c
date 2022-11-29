/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:33:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/30 01:30:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

static void		set_spcf(void (*write_specifier[9])(va_list *));
static short	get_spcf(char spcf);

void	writing(const char *str, va_list *ptr)
{
	void	(*write_specifier[9])(va_list *);

	set_spcf(write_specifier);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (get_spcf(*str) != -1)
				write_specifier[get_spcf(*str)](ptr);
			else
				write(1, str, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

static void	set_spcf(void (*write_specifier[9])(va_list *))
{
	write_specifier[0] = &spcf_c;
	write_specifier[1] = &spcf_d;
	write_specifier[2] = &spcf_i;
	write_specifier[3] = &spcf_p;
	write_specifier[4] = &spcf_s;
	write_specifier[5] = &spcf_u;
	write_specifier[6] = &spcf_x_lower;
	write_specifier[7] = &spcf_x_upper;
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
