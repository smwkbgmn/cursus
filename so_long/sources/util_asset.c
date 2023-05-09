/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:43:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_img(t_mlx mlx, char *filename);

t_asset	init_asset(t_mlx mlx)
{
	t_asset	imgs;

	printf("[start init_asset]\n");
	imgs.tile[0] = set_img(mlx, "assets/tile/empty.png");
	imgs.tile[1] = set_img(mlx, "./assets/tile/tree.png");
	imgs.tile[2] = set_img(mlx, "./assets/tile/exit.png");
	imgs.collect = set_img(mlx, "./assets/object/collectible.png");
	imgs.walk.cut[0] = set_img(mlx, "./assets/character/char_1.png");
	imgs.walk.cut[1] = set_img(mlx, "./assets/character/char_2.png");
	imgs.walk.cut[2] = set_img(mlx, "./assets/character/char_3.png");
	imgs.walk.cut[3] = set_img(mlx, "./assets/character/char_4.png");
	imgs.walk.cut[4] = set_img(mlx, "./assets/character/char_5.png");
	imgs.walk.cut[5] = set_img(mlx, "./assets/character/char_6.png");
	imgs.walk.cut[6] = set_img(mlx, "./assets/character/char_7.png");
	imgs.walk.frame = 0;
	printf("[finish init_asset]\n");
	return (imgs);
}

t_img	set_img(t_mlx mlx, char *filename)
{
	t_img	img;

	img.x = 32;
	img.y = 32;
	// printf("in - mlx.ptr %p, filename %s\n", mlx.ptr, filename);
	img.ptr = mlx_png_file_to_image(mlx.ptr, filename, &img.x, &img.y);
	printf("[finish set_img]\n");
	return (img);
}
