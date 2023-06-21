/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_loop1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:36:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void			patrol_enemy(t_char *enemy, char **map);
void			check_nearby_enemy(t_char *player, t_char enemy);
void			draw_character(t_data *data, char tile, t_coord coord);
void			put_string(t_data *data);
t_bool			is_enemy(t_char enemy, t_uint x, t_uint y);
static void		write_frame(t_data *data);
static t_bool	is_end(t_game game, t_char player);

int	loop_hook(t_data *data)
{
	if (data->enemy.frame == 139)
		patrol_enemy(&data->enemy, data->map.map);
	if (!data->player.death)
		check_nearby_enemy(&data->player, data->enemy);
	write_frame(data);
	if (is_end(data->game, data->player))
		exit_program(data);
	return (0);
}

static void	write_frame(t_data *data)
{
	t_coord	coord;
	char	tile;

	coord.y = 0;
	while (coord.y < data->map.height)
	{
		coord.x = 0;
		while (coord.x < data->map.width)
		{
			tile = ref_tile(data->map.map, coord);
			put_image(data->mlx, data->imgs.tile[0], coord);
			if (tile == WALL)
				put_image(data->mlx, data->imgs.tile[1], coord);
			else if (tile == EXIT)
				put_image(data->mlx, data->imgs.tile[2], coord);
			else if (tile == CLEC)
				put_image(data->mlx, data->imgs.collect, coord);
			else if (tile == PLYR || tile == ENMY)
				draw_character(data, tile, coord);
			coord.x++;
		}
		coord.y++;
	}
	put_string(data);
}

static t_bool	is_end(t_game game, t_char player)
{
	return ((game.collected == game.goal && game.win)
		|| (player.death && player.frame == 99));
}
