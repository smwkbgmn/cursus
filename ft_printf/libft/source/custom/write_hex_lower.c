/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 15:36:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	write_digit(short digit);

void	write_hex_lower(unsigned long num)
{
	if (num < 16)
		write_digit(num & 0xf);
	else
	{
		write_hex_lower(num >> 4);
		write_digit(num & 0xf);
	}
}

static void	write_digit(short digit)
{
	write(1, &"0123456789abcdef"[digit], 1);
}
