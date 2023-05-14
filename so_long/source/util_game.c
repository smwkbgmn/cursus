/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 20:16:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_coord_target(t_map map, t_char *chartr, char target);
void	set_game_goal(t_map map, t_game *game);

t_char	init_character(t_map map, char target)
{
	t_char	chartr;

	chartr.frame = 0;
	set_coord_target(map, &chartr, target);
	if (chartr.coord.x < map.width / 2)
		chartr.direction = RIGHT;
	else
		chartr.direction = LEFT;
	chartr.move = 0;
	chartr.death = FALSE;
	return (chartr);
}

void	set_coord_target(t_map map, t_char *chartr, char target)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < map.height)
	{
		coord.x = 0;
		while (coord.x < map.width)
		{
			if (ref_tile(map.map, coord) == target)
			{
				chartr->coord = coord;
			}
			coord.x++;
		}
		coord.y++;
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
	t_coord	coord;

	coord.y = 0;
	game->goal = 0;
	while (coord.y < map.height)
	{
		coord.x = 0;
		while (coord.x < map.width)
		{
			if (ref_tile(map.map, coord) == CLEC)
				game->goal++;
			coord.x++;
		}
		coord.y++;
	}
}
