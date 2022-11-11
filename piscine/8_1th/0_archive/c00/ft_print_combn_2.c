/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:55:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 15:23:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *num, int n);
void	print(char *num, int n);
void	up(char *num, int n, int idx, int check);

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
	while(idx < n)
	{
		num[idx] = '0' + idx;
		idx++;
	}
}

void	print(char *num, int n)
{
	write(1, num, n);
	if (num[n - 1] == '9' && n != 1)
	{
		write(1, ", ", 2);
		up(num, n, 1, 0);
		print(num, n);
	}
	else if (num[0] < (10 - n) + '0')
	{
		write(1, ", ", 2);
		num[n - 1]++;
		print(num, n);
	}
}

void	up(char *num, int n, int idx, int check)
{
	if (idx < n)
	{
		if (num[idx] == '9' - (n - (idx + 1)))
		{
			if (check == 0)
			{
				num[idx - 1]++;
				num[idx] = num[idx - 1] + 1;
				check = 1;
			}
			else if (check == 1)
			{
				num[idx] = num[idx - 1] + 1;
			}
		}
		up(num, n, ++idx, check);
	}
}
