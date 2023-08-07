/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/01 13:42:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	put_image(t_mlx mlx, t_img img, t_coord coord)
{
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr,
		coord.x * 32, coord.y * 32);
}

void	put_string(t_data *data)
{
	char	*str_num;

	str_num = ft_itoa(data->player.move);
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		(data->player.coord.x + 1) * 32 - 2, data->player.coord.y * 32,
		0x00FFFFFF, str_num);
	ft_free(str_num);
}
