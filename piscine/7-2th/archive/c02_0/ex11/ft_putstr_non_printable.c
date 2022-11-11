/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:18:41 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 23:04:15 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter)
{
	write (1, &letter, 1);
}

void	convert(int decimal)
{
	char	hex;

	hex = decimal % 16;
	if ('0' + hex > '9')
		ft_putchar ('a' + hex - 10);
	else
		ft_putchar ('0' + hex);
	while (decimal > 15)
	{
		decimal /= 16;	
		convert (decimal);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	moving;
	int decimal;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] < 32 || str[moving] > 127)
		{
			ft_putchar (92);
			ft_putchar (48);
			decimal = str[moving];
			convert (decimal);
		}
		else
			ft_putchar (str[moving]);
		moving++;
	}
	ft_putchar ('\n');	
}


