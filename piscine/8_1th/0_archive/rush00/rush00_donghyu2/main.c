/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:03:22 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/27 22:01:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush02(int x, int y);
int	input_validation(int argc, char **argv);
int	get_number(char *argv);

int	main(int argc, char **argv)
{
	if (input_validation(argc, argv) == 1)
	{
		write (1, "wrong input\n", 12);
		return (0);
	}

	rush02(get_number(argv[1]), get_number(argv[2]));
	
	return (0);
}

int	input_validation(int argc, char **argv)
{
	int	idx1;
	int idx2;

	if (argc != 3)
		return (1);
	
	idx1 = 1;
	while (argv[idx1])
	{
		idx2 = 0;
		while (argv[idx1][idx2])
		{
			if (argv[idx1][idx2] < '0' || argv[idx1][idx2] > '9')
				return (1);
			idx2++;;
		}
		idx1++;
	}
	return (0);
}

int	get_number(char *argv)
{
	int	num;
	int	idx;

	num = 0;
	idx = 0;
	while(argv[idx])
	{
		num = num * 10 + argv[idx] - '0';
		idx++;
	}
	if (num <= 0)
		write(1, "wrong input (overflow)\n", 23);
	return (num);
}
