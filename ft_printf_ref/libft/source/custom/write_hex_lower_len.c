/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_lower_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/02 01:40:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t	write_digit(short digit);

size_t	write_hex_lower_len(unsigned int num)
{
	short	hex[20];
	size_t	len;
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
		len += write_digit(hex[idx--]);
	return (len);
}

static size_t	write_digit(short digit)
{
	return (write(1, &"0123456789abcdef"[digit], 1));
}
