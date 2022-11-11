/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:13:22 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 11:14:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	valid_char(t_map *map);
int	is_printable(char letter);

int	valid_info1(t_map *map)
{
	if (valid_char(map) == 0)
		return (0);
	else if (map->row <= 0)
		return (0);
	else
		return (1);
}

int	valid_char(t_map *map)
{
	if (map->empty == map->obstc)
		return (0);
	else if (map->obstc == map->full)
		return (0);
	else if (map->full == map->empty)
		return (0);
	else if (is_printable(map->empty) == 0)
		return (0);
	else if (is_printable(map->obstc) == 0)
		return (0);
	else if (is_printable(map->full) == 0)
		return (0);
	else
		return (1);
}

int	is_printable(char letter)
{
	if (' ' <= letter && letter <= '~')
		return (1);
	else
		return (0);
}

int	valid_map(t_map *map)
{
	int	r;
	int	c;

	r = 0;
	while (r < map->row)
	{
		c = 0;
		while (c < map->col + 1)
		{
			if (map->map[r][c] < 0)
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}
