/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:31:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_asset(void *mlx, t_asset *imgs)
{
	set_img(mlx, &imgs->tile[0], "asset/tile/empty.png");
	set_img(mlx, &imgs->tile[1], "asset/tile/tree.png");
	set_img(mlx, &imgs->tile[2], "asset/tile/exit.png");
	set_img(mlx, &imgs->collect, "asset/object/collectible.png");
	set_img_char(mlx, &imgs->player_walk, "asset/character/player/Walk", 7);
	set_img_char(mlx, &imgs->player_death, "asset/character/player/Death", 10);
	set_img_char(mlx, &imgs->enemy, "asset/character/enemy/Walk", 14);
}

void	set_img(void *mlx, t_img *img, char *name)
{
	img->width = 32;
	img->height = 32;
	img->ptr = mlx_png_file_to_image(mlx, name, &img->width, &img->height);
	if (!img->ptr)
		exit_with_error("mlx_png_file_to_image");
}
