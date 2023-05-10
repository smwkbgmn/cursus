/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 17:39:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_game	init_game(char **map)
{
	t_game	player;
	t_uint	y;
	t_uint	x;

	player.collected = 0;
	player.goal = 0;
	player.move = 0;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 20)
		{
			if (map[y][x] == PLYR)
			{
				player.x = x;
				player.y = y;
			}
			else if (map[y][x] == CLEC)
				player.goal++;
			x++;
		}
		y++;
	}
	if (player.x < 10)
		player.direction = RIGHT;
	else
		player.direction = LEFT;
	player.frame = 0;
	player.end = FALSE;
	return (player);
}
