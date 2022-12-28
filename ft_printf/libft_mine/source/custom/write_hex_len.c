/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/12 20:12:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	write_digit(short digit, short flag);

int	write_hex_len(unsigned int num, short flag)
{
	short	hex[20];
	int		len;
	int		idx;

	len = 0;
	idx = 0;
	while (num > 15)
	{
		hex[idx++] = num & 0xf;
		num = num >> 4;
	}
	hex[idx] = num;
	while (idx >= 0)
		len += write_digit(hex[idx--], flag);
	return (len);
}

static int	write_digit(short digit, short flag)
{
	if (flag == 0)
		return (write(1, &"0123456789abcdef"[digit], 1));
	else
		return (write(1, &"0123456789ABCDEF"[digit], 1));
}
