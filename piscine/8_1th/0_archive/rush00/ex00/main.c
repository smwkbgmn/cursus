/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:13:18 by geonwule          #+#    #+#             */
/*   Updated: 2022/08/27 21:52:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (42);
}

int	x_y_output(char *argv, int i, int xy)
{
	while (argv[i])
	{
		xy = xy * 10 + argv[i] - '0';
		i++;
	}
	return (xy);
}

int	main(int argc, char **argv)
{
	int	i;
	int	x;
	int	y;

	if (error_check(argc, argv) == -1)
		return (0);
	i = 0;
	x = 0;
	y = 0;
	x = x_y_output(argv[1], i, x);
	y = x_y_output(argv[2], i, y);
	if (x <= 0 || y <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	rush02(x, y);
}
