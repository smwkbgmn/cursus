/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:55:33 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 11:55:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *num, int n);
void	print(char *num, int n);
void	up(char *num, int idx);

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

	while (num[0] < (10 - n) + '0')
	{
		write(1, ", ", 2);
		if (num[n - 1] != '9')
			num[n - 1]++;
		print(num, n);
		if (num[n - 1] == '9')
			up(num, n - 1);
	}
}

void	up(char *num, int idx)
{
	int	idx_t;

	idx_t = idx;
	while (idx > 0)
	{
		if (num[idx] == '9' - (idx_t - idx))
		{
			num[idx - 1]++;
			num[idx] = num[idx - 1] + 1;
		}
		up(num, --idx);
	}

//	if(num[idx_t] == '9')
//		num[idx_t] = num[idx_t - 1] + 1;
}
