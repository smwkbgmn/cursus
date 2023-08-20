/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:33:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:50:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		check_direction(t_direc *direction, t_uint cnt);
static t_bool	is_enemy(t_char enemy, t_uint x, t_uint y);

void	patrol_enemy(t_char *enemy, char **map)
{
	static t_uint	cnt;
	t_coord			moved;

	check_direction(&enemy->direction, cnt);
	moved.x = enemy->coord.x + (cnt == 1) - (cnt == 3);
	moved.y = enemy->coord.y + (cnt == 2) - (cnt == 0);
	if (map[moved.y][moved.x] == EMTY)
		swap_tile(map, enemy, moved, ENMY);
	cnt = (cnt + 1) * (cnt != 3);
}

void	check_nearby_enemy(t_char *player, t_char enemy)
{
	t_uint	x;
	t_uint	y;

	x = player->coord.x;
	y = player->coord.y;
	if (is_enemy(enemy, x - 1, y) || is_enemy(enemy, x + 1, y)
		|| is_enemy(enemy, x, y - 1) || is_enemy(enemy, x, y + 1))
	{
		player->frame = 0;
		player->death = TRUE;
	}
}

static void	check_direction(t_direc *direction, t_uint cnt)
{
	if (*direction == LEFT && cnt == 1)
		*direction = RIGHT;
	else if (*direction == RIGHT && cnt == 3)
		*direction = LEFT;
}

static t_bool	is_enemy(t_char enemy, t_uint x, t_uint y)
{
	return (enemy.coord.x == x && enemy.coord.y == y);
}
