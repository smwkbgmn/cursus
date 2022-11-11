/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:56:36 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 14:10:24 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	futchar(char letter);
void	print_number(int number);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			print_number (a);
			futchar (' ');
			print_number (b);
			if (a != 98 && a != 99)
			{
				futchar (',');
				futchar (' ');
			}
			b++;
		}
		a++;
	}
}

void	futchar(char letter)
{
	write (1, &letter, 1);
}

void	print_number(int number)
{
	futchar (number / 10 + '0');
	futchar (number % 10 + '0');
}
