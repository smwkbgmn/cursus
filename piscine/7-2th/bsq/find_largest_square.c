/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:56:54 by pji               #+#    #+#             */
/*   Updated: 2022/06/09 11:48:25 by pji              ###   ########.fr       */
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
	int			collision_x;

	temp.y = 0;
	biggest.size = 0;
	while (map[temp.y])
	{
		temp.x = 0;
		while (map[temp.y][temp.x])
		{
			temp.size = find_point(temp, map, structure, &collision_x);
			if (biggest.size < temp.size)
				biggest = temp;
			if (collision_x != -1 && map[temp.y][collision_x])
				temp.x = collision_x + 1;
			else
				++temp.x;
		}
		++temp.y;
	}
	return (biggest);
}

int	find_point(t_square point, char **map, char *structure, int *collision_x)
{
	point.size = 0;
	*collision_x = -1;
	while (*collision_x == -1)
	{
		++point.size;
		*collision_x = check_square(point, map, structure);
	}
	return (point.size - 1);
}

int	check_square(t_square point, char **map, char *structure)
{
	int	count;

	count = 0;
	while (count < point.size)
	{
		if (map[point.y + point.size - 1])
			return (point.x + count);
		if (map[point.y + point.size - 1][point.x + count])
			return (point.x + count);
		if (map[point.y + point.size - 1][point.x + count] == structure[WALL])
			return (point.x + count);
		++count;
	}
	count = 0;
	while (count < point.size)
	{
		if (map[point.y + count] == 0)
			return (point.x + point.size - 1);
		if (map[point.y + count][point.x + point.size - 1])
			return (point.x + point.size - 1);
		if (map[point.y + count][point.x + point.size - 1] == structure[WALL])
			return (point.x + point.size - 1);
		++count;
	}
	return (-1);
}
