/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:11:53 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/02 01:48:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_putnbr_len(int n, size_t len)
{
	if (n == -2147483648)
		len += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		len += ft_putnbr_len(n * -1, len);
		len += 1;
	}
	else if (n < 10)
		len += write(1, &"0123456789"[n], 1);
	else
	{
		len += ft_putnbr_len(n / 10, len);
		len += write(1, &"0123456789"[n % 10], 1);
	}
	return (len);
}
