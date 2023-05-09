/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:34:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:26:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	dose_meet_goal(t_game player);
t_bool	is_arrow(int keycode);
t_bool	is_moveable(char map);

int	key_hook(int keycode, t_data *data)
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
		if (is_moveable(tile))
		{
			if (tile == CLEC)
				data->player.collected++;
			if (tile != WALL
				|| (tile == EXIT && dose_meet_goal(data->player)))
			{
				data->map.map[data->player.y][data->player.x] = EMTY;
				data->map.map[y][x] = PLYR;
				data->player.x = x;
				data->player.y = y;
			}
		}
		printf("char position %d.%d\n", data->player.x, data->player.y);
	}
	return (0);
}

t_bool	is_arrow(int keycode)
{
	return (keycode == W || keycode == A
		|| keycode == S || keycode == D);
}

t_bool	is_moveable(char tile)
{
	return (tile == EMTY || tile == CLEC || tile == EXIT);
}

t_bool	dose_meet_goal(t_game player)
{
	return (player.collected == player.goal);
}
