/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:18:41 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 17:46:01 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter)
{
	write (1, &letter, 1);
}

void	convert(int decimal)
{
	while (decimal > 15)
	{
		decimal /= 16;
		convert (decimal);
	}
	ft_putchar ("0123456789abcdef"[decimal % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	moving;
	int	decimal;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] < 32 || str[moving] > 127)
		{
			ft_putchar (92);
			if (str[moving] < 16)
				ft_putchar ('0');
			decimal = (unsigned)str[moving];
			convert (decimal);
		}
		else
			ft_putchar (str[moving]);
		moving++;
	}
	ft_putchar ('\n');
}
