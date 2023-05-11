/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 02:14:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

#include "so_long.h"

void	set_coordi_target(t_map map, t_char *chartr, char target);
void	set_game_goal(t_map map, t_game *game);

t_char	init_character(t_map map, char target)
{
	t_char	chartr;

	chartr.frame = 0;
	set_coordi_target(map, &chartr, target);
	if (chartr.x < map.width / 2)
		chartr.direction = RIGHT;
	else
		chartr.direction = LEFT;
	chartr.move = 0;
	return (chartr);
}

void	set_coordi_target(t_map map, t_char *chartr, char target)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == target)
			{
				chartr->x = x;
				chartr->y = y;
			}
			x++;
		}
		y++;
	}
}

t_game	init_game(t_map map)
{
	t_game	game;

	set_game_goal(map, &game);
	game.collected = 0;
	game.win = FALSE;
	return (game);
}

void	set_game_goal(t_map map, t_game *game)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	game->goal = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == CLEC)
				game->goal++;
			x++;
		}
		y++;
	}
}
