/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:34:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 18:19:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_bool	dose_meet_goal(t_game player);
t_bool	is_arrow(int keycode);
t_bool	is_moveable(t_game player, char map);

int	move_character(int keycode, t_data *data)
{
	char	tile;
	t_uint	x;
	t_uint	y;

	if (is_arrow(keycode))
	{
		x = data->player.x;
		y = data->player.y;
		if (keycode == W)
			y--;
		else if (keycode == A)
			x--;
		else if (keycode == S)
			y++;
		else if (keycode == D)
			x++;
		tile = data->map.map[y][x];
		if (is_moveable(data->player, tile))
		{
			if (tile == CLEC)
				data->player.collected++;
			data->map.map[data->player.y][data->player.x] = EMTY;
			data->map.map[y][x] = PLYR;
			if (data->player.x > x)
				data->player.direction = LEFT;
			else if (data->player.x < x)
				data->player.direction = RIGHT;
			data->player.x = x;
			data->player.y = y;
			if (tile == EXIT)
				data->player.end = TRUE;
		}
		// printf("position %d,%d[%d]\n", data->player.x, data->player.y, data->player.direction);
	}
	return (0);
}

t_bool	is_arrow(int keycode)
{
	return (keycode == W || keycode == A
		|| keycode == S || keycode == D);
}

t_bool	is_moveable(t_game player, char tile)
{
	return (tile == EMTY || tile == CLEC
		|| (tile == EXIT && player.collected == player.goal));
}

// t_bool	dose_meet_goal(t_game player)
// {
// 	return (player.collected == player.goal);
// }
