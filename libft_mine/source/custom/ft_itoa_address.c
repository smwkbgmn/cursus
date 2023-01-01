/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 11:31:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static char	dec_to_hex_char(short dec);

char	*ft_itoa_address(unsigned long addr)
{
	char	*hex;
	short	dec[50];
	short	idx_dec;
	short	idx_hex;

	idx_dec = 0;
	while (addr > 15)
	{
		dec[idx_dec++] = addr & 0xf;
		addr = addr >> 4;
	}
	dec[idx_dec] = addr;
	hex = malloc(idx_dec + 3);
	if (hex)
	{
		hex[0] = '0';
		hex[1] = 'x';
		idx_hex = 2;
		while (idx_dec >= 0)
			hex[idx_hex++] = dec_to_hex_char(dec[idx_dec--]);
	}
	return (hex);
}

static char	dec_to_hex_char(short dec)
{
	return ("0123456789abcdef"[dec]);
}
