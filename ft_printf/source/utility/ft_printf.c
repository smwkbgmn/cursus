/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:06:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/07 00:29:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

static void		set_spcf(size_t (*write_specifier[9])(va_list *));
static short	get_spcf(char spcf);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	size_t (*write_specifier[9])(va_list *);
	set_spcf(write_specifier);
	va_start(ptr, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (get_spcf(*str) != -1)
				len += write_specifier[get_spcf(*str)](&ptr);
			else
				len += write(1, str, 1);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ptr);
	return (len);
}

static void	set_spcf(size_t (*write_specifier[9])(va_list *))
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
