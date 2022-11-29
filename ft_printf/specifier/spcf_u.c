/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:26 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 23:11:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static void	ft_putnbr_uint(unsigned int num);

void	spcf_u(va_list *ptr)
{
	unsigned int	num;

	num = va_arg(*ptr, unsigned int);
	ft_putnbr_uint(num);
}

static void	ft_putnbr_uint(unsigned int num)
{
	if (num < 10)
		write(1, &"0123456789"[num], 1);
	else
	{
		ft_putnbr_uint(num / 10);
		write(1, &"0123456789"[num % 10], 1);
	}	
}
