/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:32:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/01 13:42:35 by donghyu2         ###   ########.fr       */
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
