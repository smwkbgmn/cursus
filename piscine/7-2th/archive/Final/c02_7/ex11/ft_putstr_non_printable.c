/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:18:41 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/02 11:55:05 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter)
{
	write (1, &letter, 1);
}

void	convert(int decimal)
{
	int	digit;

	digit = decimal % 16;
	if (decimal > 15)
	{
		decimal /= 16;
		convert (decimal);
	}
	ft_putchar ("0123456789abcdef"[digit]);
}

void	ft_putstr_non_printable(char *str)
{
	int	moving;
	int	decimal;

	moving = 0;
	while (str[moving])
	{
		decimal = (unsigned char)str[moving];
		if (decimal < 32 || decimal > 126)
		{
			ft_putchar (92);
			if (decimal < 16)
				ft_putchar ('0');
			convert (decimal);
		}
		else
			ft_putchar (str[moving]);
		moving++;
	}
}
