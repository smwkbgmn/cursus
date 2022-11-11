/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:57:05 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:57:06 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	futchar(char letter)
{
	write (1, &letter, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		futchar ('-');
		write (1, &"2147483648", 10);
	}
	else if (nb < 0)
	{
		nb *= -1;
		futchar ('-');
		ft_putnbr (nb);
	}
	else if (nb > 9)
	{
		ft_putnbr (nb / 10);
		futchar (nb % 10 + '0');
	}
	else
		futchar (nb + '0');
}
