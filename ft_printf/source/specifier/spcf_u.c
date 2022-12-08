/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:26 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 18:10:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static int	ft_putnbr_uint_len(unsigned int num, int len);

int	spcf_u(va_list *ptr)
{
	unsigned int	num;

	num = va_arg(*ptr, unsigned int);
	return (ft_putnbr_uint_len(num, 0));
}

static int	ft_putnbr_uint_len(unsigned int num, int len)
{
	if (num < 10)
		len += write(1, &"0123456789"[num], 1);
	else
	{
		len += ft_putnbr_uint_len(num / 10, len);
		len += write(1, &"0123456789"[num % 10], 1);
	}
	return (len);
}
