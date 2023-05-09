/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:30:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

void	put_image(t_mlx mlx, t_img img, int x, int y);

int	write_frame(t_data *data)
{
	t_uint	x;
	t_uint	y;

	// printf("[start write_frame]\n");
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			put_image(data->mlx, data->imgs.tile[0], x * 32, y * 32);
			// printf("[draw tile]\n");
			if (data->map.map[y][x] == WALL)
			{
				put_image(data->mlx, data->imgs.tile[1], x * 32, y * 32);
				// printf("[draw wall]\n");
			}
			else if (data->map.map[y][x] == EXIT)
			{
				put_image(data->mlx, data->imgs.tile[2], x * 32, y * 32);
				// printf("[draw exit]\n");
			}
			else if (data->map.map[y][x] == CLEC)
			{
				put_image(data->mlx, data->imgs.collect, x * 32, y * 32);
				// printf("[draw collectible]\n");
			}
			else if (data->map.map[y][x] == PLYR)
			{
				put_image(data->mlx, data->imgs.walk.cut[data->imgs.walk.frame / 10], x * 32, y * 32);
				data->imgs.walk.frame++;
				data->imgs.walk.frame %= 70;
				// printf("[draw player]\n");
			}
			x++;
		}
		y++;
	}
	// printf("[finish write_frame]\n");
	return (0);
}

void	put_image(t_mlx mlx, t_img img, int x, int y)
{
	// printf("ptr_mlx %p, ptr_window %p, ptr_image %p, position %d.%d\n", mlx.ptr, mlx.window, img.ptr, x, y);
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr, x, y);
	// printf("finish put_image\n");
}
