/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:59:10 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/24 13:43:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *num);
void	print(char *num);
void	check(char *num, int idx);

int	main()
{
	char	num[4];

	init(num);
	print(num);

	return (0);
}

void	init(char *num)
{
	int	idx;
	
	idx = 0;
	while(idx < 3)
	{
		num[idx] = '0' + idx;
		idx++;
	}
}

void	print(char *num)
{
	check(num, 2);

	write(1, num, 3);
	write(1, ", ", 2);

	while(num[0] < '7')
	{
		num[2]++;
		print(num);
	}
}

void	check(char *num, int idx)
{
	while(idx > 0)
	{
		if (num[idx] > '9' - (2 - idx))
		{
			num[idx - 1]++;
			num[idx] = num[idx - 1] + 1;
		}
		check(num, --idx);
	}

	if(num[2] > '9')
		num[2] = num[1] + 1;
}
