/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/02 02:20:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t	write_digit(short digit);

size_t	write_address(unsigned long addr)
{
	short	hex[20];
	size_t	len;
	int		idx;

	len = 0;
	idx = 0;
	while (addr > 15)
	{
		hex[idx++] = addr & 0xf;
		addr = addr >> 4;
	}
	hex[idx] = addr;
	len += write(1, "0x", 2);
	while (idx >= 0)
		len += write_digit(hex[idx--]);
	return (len);
}

static size_t	write_digit(short digit)
{
	return (write(1, &"0123456789abcdef"[digit], 1));
}
