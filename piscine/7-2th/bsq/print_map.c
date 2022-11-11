/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:18:38 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 11:19:55 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "square.h"
#include "print_map.h"
#include <unistd.h>
#define BOX 2

void	print_map(char **map, char structure[4], t_square square)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_square(square, row, col))
				ft_putchar(structure[BOX]);
			else
				ft_putchar(map[row][col]);
			++col;
		}
		ft_putchar('\n');
		++row;
	}		
}

void	ft_putchar(char character)
{
	write (1, &character, 1);
}

int	is_square(t_square square, int row, int col)
{
	if (col >= square.x && col < square.x + square.size)
		if (row >= square.y && row < square.y + square.size)
			return (1);
	return (0);
}
