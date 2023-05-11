/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:34:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 02:02:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_bool	is_arrow(int keycode);
t_bool	is_moveable(t_game game, char map);

int	move_character(int keycode, t_data *data)
{
	char	tile;
	t_uint	x;
	t_uint	y;

	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx.ptr, data->mlx.window);
		exit(0);
	}
	else if (is_arrow(keycode))
	{
		x = data->player.x;
		y = data->player.y;
		if (keycode == W)
			y--;
		else if (keycode == A)
		{
			x--;
			data->player.direction = LEFT;
		}
		else if (keycode == S)
			y++;
		else if (keycode == D)
		{
			x++;
			data->player.direction = RIGHT;
		}
		tile = data->map.map[y][x];
		if (is_moveable(data->game, tile))
		{
			data->player.move++;
			if (tile == CLEC)
				data->game.collected++;
			data->map.map[data->player.y][data->player.x] = EMTY;
			data->map.map[y][x] = PLYR;
			data->player.x = x;
			data->player.y = y;
			if (tile == EXIT)
				data->game.win = TRUE;
		}
	}
	return (0);
}

t_bool	is_arrow(int keycode)
{
	return (keycode == W || keycode == A
		|| keycode == S || keycode == D);
}

t_bool	is_moveable(t_game game, char tile)
{
	return (tile == EMTY || tile == CLEC
		|| (tile == EXIT && game.collected == game.goal));
}
