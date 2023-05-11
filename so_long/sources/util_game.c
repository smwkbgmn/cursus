/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/11 12:46:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_char	init_player(t_game *game, char **map)
{
	t_char	player;
	t_uint	y;
	t_uint	x;

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
				game->goal++;
			x++;
		}
		y++;
	}
	if (player.x < 10)
		player.direction = RIGHT;
	else
		player.direction = LEFT;
	player.frame = 0;
	player.move = 0;
	return (player);
}

t_game	init_game(void)
{
	t_game	game;

	game.collected = 0;
	game.goal = 0;
	game.win = FALSE;
	return (game);
}
