/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:29:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:40:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	write_digit(short digit, short flag);

void	write_hex(unsigned int num, short flag)
{
	if (num < 16)
		write_digit(num & 0xf, flag);
	else
	{
		write_hex(num >> 4, flag);
		write_digit(num & 0xf, flag);
	}
}

static void	write_digit(short digit, short flag)
{
	if (flag == 0)
		write(1, &"0123456789abcdef"[digit], 1);
	else
		write(1, &"0123456789ABCDEF"[digit], 1);
}
