/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:52:41 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/24 14:11:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int num);

void	ft_print_comb2(void)
{
	int	num[2];

	num[0] = 0;
	while (num[0] < 99)
	{
		num[1] = num[0] + 1;
		while (num[1] < 100)
		{
			print(num[0]);
			write(1, " ", 1);
			print(num[1]);
			if (num[0] != 98)
				write(1, ", ", 2);
			num[1]++;
		}
		num[0]++;
	}
}

void	print(int num)
{
	char	div;
	char	mod;

	div = num / 10 + '0';
	mod = num % 10 + '0';
	write(1, &div, 1);
	write(1, &mod, 1);
}
