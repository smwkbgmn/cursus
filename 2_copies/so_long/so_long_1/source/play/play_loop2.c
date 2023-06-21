/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_loop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:32:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/13 15:06:30 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_character(t_mlx mlx, t_char *chart,
				t_img_char imgs, t_coord coord);

void	draw_character(t_data *data, char tile, t_coord coord)
{
	if (tile == PLYR)
	{
		if (!data->player.death)
			put_character(data->mlx, &data->player,
				data->imgs.player_walk, coord);
		else
			put_character(data->mlx, &data->player,
				data->imgs.player_death, coord);
	}
	else if (tile == ENMY)
		put_character(data->mlx, &data->enemy,
			data->imgs.enemy, coord);
}

static void	put_character(t_mlx mlx, t_char *chart,
				t_img_char imgs, t_coord coord)
{
	put_image(mlx, imgs.cut[chart->direction][chart->frame / 10], coord);
	chart->frame = (chart->frame + 1) % (imgs.cnt_img * 10);
}

void	put_image(t_mlx mlx, t_img img, t_coord coord)
{
	mlx_put_image_to_window(mlx.ptr, mlx.window, img.ptr,
		coord.x * 32, coord.y * 32);
}

void	put_string(t_data *data)
{
	mlx_string_put(data->mlx.ptr, data->mlx.window,
		(data->player.coord.x + 1) * 32 - 2, data->player.coord.y * 32,
		0x00FFFFFF, ft_itoa(data->player.move));
}
