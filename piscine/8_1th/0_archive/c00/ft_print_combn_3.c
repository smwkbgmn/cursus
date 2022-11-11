/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:55:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 17:57:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *num, int n);
void	print(char *num, int n);
void	up(char *num, int n, int idx);

void	ft_print_combn(int n)
{
	char	num[10];

	if (0 < n && n < 10)
	{
		init(num, n);
		print(num, n);
	}
}

void	init(char *num, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		num[idx] = idx + '0';
		idx++;
	}
}

void	print(char *num, int n)
{
	write(1, num, n);
	if (num[0] < (10 - n) + '0')
	{
		write(1, ", ", 2);
		if (num[n - 1] == '9' && n != 1)
			up(num, n, 1);
		else
			num[n - 1]++;
		print(num, n);
	}
}

void	up(char *num, int n, int idx)
{
	if (idx < n)
	{
		if (num[idx] == '9' - (n - (idx + 1)))
		{
			num[idx - 1]++;
			if (idx < n - 1)
			{
				while (idx < n)
				{
					num[idx] = num[idx - 1] + 1;
					idx++;
				}
			}
			else
				num[idx] = num[idx - 1] + 1;
		}
		up(num, n, ++idx);
	}
}
