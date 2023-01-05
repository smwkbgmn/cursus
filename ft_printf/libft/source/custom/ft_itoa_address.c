/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:40:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	dec_to_hex_char(short dec);

char	*ft_itoa_address(unsigned long addr)
{
	char	*hex;
	short	dec[50];
	short	i_dec;
	short	i_hex;

	i_dec = 0;
	while (addr > 15)
	{
		dec[i_dec++] = addr & 0xf;
		addr = addr >> 4;
	}
	dec[i_dec] = addr;
	hex = malloc(2 + i_dec + 1);
	if (hex)
	{
		hex[0] = '0';
		hex[1] = 'x';
		i_hex = 2;
		while (i_dec >= 0)
			hex[i_hex++] = dec_to_hex_char(dec[i_dec--]);
	}
	return (hex);
}

static char	dec_to_hex_char(short dec)
{
	return ("0123456789abcdef"[dec]);
}
