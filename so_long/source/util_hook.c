/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:34:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 15:48:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_arrow(int keycode);
static t_bool	is_moveable(t_game game, char map);
static void		check_direction(t_direc *direction, int keycode);

int	key_hook(int keycode, t_data *data)
{
	char	tile;
	t_coord	moved;

	if (keycode == ESC)
		exit_program(data);
	else if (is_arrow(keycode) && !data->player.death)
	{
		check_direction(&data->player.direction, keycode);
		moved.x = data->player.coord.x - (keycode == A) + (keycode == D);
		moved.y = data->player.coord.y - (keycode == W) + (keycode == S);
		tile = ref_tile(data->map.map, moved);
		if (is_moveable(data->game, tile))
		{
			data->player.move++;
			if (tile == CLEC)
				data->game.collected++;
			swap_tile(data->map.map, &data->player, moved, PLYR);
			if (tile == EXIT)
				data->game.win = TRUE;
		}
	}
	return (0);
}

static t_bool	is_arrow(int keycode)
{
	return (keycode == W || keycode == A
		|| keycode == S || keycode == D);
}

static t_bool	is_moveable(t_game game, char tile)
{
	return (tile == EMTY || tile == CLEC
		|| (tile == EXIT && game.collected == game.goal));
}

static void	check_direction(t_direc *direction, int keycode)
{
	if (*direction == RIGHT && keycode == A)
		*direction = LEFT;
	else if (*direction == LEFT && keycode == D)
		*direction = RIGHT;
}

