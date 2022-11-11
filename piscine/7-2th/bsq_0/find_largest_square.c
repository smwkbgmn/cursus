/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:56:54 by pji               #+#    #+#             */
/*   Updated: 2022/06/08 19:41:15 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "find_largest_square.h"
#define EMPTY 0
#define WALL 1
#define BOX 2

t_square	find_largest_square(char **map, char *structure)
{
	t_square	biggest;
	t_square	temp;

	temp.y = 0;
	biggest.size = 0;
	while (map[temp.y] != 0)
	{
		temp.x = 0;
		while (map[temp.y][temp.x] != '\0')
		{
			temp.size = find_point(temp, map, structure);
			if (biggest.size < temp.size)
			{
				biggest.x = temp.x;
				biggest.y = temp.y;
				biggest.size = temp.size;
			}
			++temp.x;
		}
		++temp.y;
	}
	return (biggest);
}

int	find_point(t_square point, char **map, char *structure)
{
	point.size = 1;
	while (!check_square(point, map, structure))
	{
		++point.size;
	}
	return (point.size - 1);
}

int	check_square(t_square point, char **map, char *structure)
{
	int	count;

	count = 0;
	while (count < point.size)
	{
		if (map[point.y + point.size - 1] == 0)
			return (1);
		if (map[point.y + point.size - 1][point.x + count] == '\0')
			return (1);
		if (map[point.y + point.size - 1][point.x + count] == structure[WALL])
			return (1);
		++count;
	}
	count = 0;
	while (count < point.size)
	{
		if (map[point.y + count] == 0)
			return (1);
		if (map[point.y + count][point.x + point.size - 1] == '\0')
			return (1);
		if (map[point.y + count][point.x + point.size - 1] == structure[WALL])
			return (1);
		++count;
	}
	return (0);
}
