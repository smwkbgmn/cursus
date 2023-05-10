/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 15:46:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_images(t_data *data);
void	put_image(t_mlx mlx, t_img img, int x, int y);
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
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
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
				put_image(data->mlx, data->imgs.walk[data->player.direction][data->player.frame / 10], x * 32, y * 32);
				data->player.frame = (data->player.frame + 1) % 70;
			}
			x++;
		}
		y++;
	}
}

void	put_image(t_mlx mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr, x, y);
}

t_bool	check_win(t_data *data)
{
	return (data->player.collected == data->player.goal
		&& data->player.end == TRUE);
}
