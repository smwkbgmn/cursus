/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 02:16:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "so_long.h"

void	draw_images(t_data *data);
void	put_image(t_mlx mlx, t_img img, int x, int y);
void	put_string(t_data *data);
t_bool	check_win(t_data *data);

int	write_frame(t_data *data)
{
	draw_images(data);
	if (check_win(data))
	{
		printf("im done\n");
		mlx_destroy_window(data->mlx.ptr, data->mlx.window);
		exit(0);
	}
	return (0);
}

void	draw_images(t_data *data)
{
	char	tile;
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			tile = data->map.map[y][x];
			put_image(data->mlx, data->imgs.tile[0], x * 32, y * 32);
			if (tile == WALL)
				put_image(data->mlx, data->imgs.tile[1], x * 32, y * 32);
			else if (tile == EXIT)
				put_image(data->mlx, data->imgs.tile[2], x * 32, y * 32);
			else if (tile == CLEC)
				put_image(data->mlx, data->imgs.collect, x * 32, y * 32);
			else if (tile == PLYR)
			{
				put_image(data->mlx, data->imgs.player_walk[data->player.direction][data->player.frame / 10], x * 32, y * 32);
				data->player.frame = (data->player.frame + 1) % 70;
			}
			else if (tile == ENMY)
			{
				put_image(data->mlx, data->imgs.enemy[data->enemy.direction][data->enemy.frame / 10], x * 32, y * 32);
				data->enemy.frame = (data->enemy.frame + 1) % 140;
			}
			x++;
		}
		y++;
	}
	put_string(data);
}

void	put_image(t_mlx mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr, x, y);
}

void	put_string(t_data *data)
{
	char	*str;

	str = ft_itoa(data->player.move);
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		(data->player.x + 1) * 32 - 2, data->player.y * 32, 0x00FFFFFF, str);
}

t_bool	check_win(t_data *data)
{
	return (data->game.collected == data->game.goal
		&& data->game.win == TRUE);
}
