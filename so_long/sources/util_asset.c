/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 15:19:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_img(t_mlx mlx, char *filename);

t_asset	init_asset(t_mlx mlx)
{
	t_asset	imgs;

	printf("[start init_asset]\n");
	imgs.tile[0] = set_img(mlx, "./assets/tile/empty.png");
	imgs.tile[1] = set_img(mlx, "./assets/tile/tree.png");
	imgs.tile[2] = set_img(mlx, "./assets/tile/exit.png");
	imgs.collect = set_img(mlx, "./assets/object/collectible.png");
	imgs.walk[LEFT][0] = set_img(mlx, "./assets/character/walk/Walk_L_1.png");
	imgs.walk[LEFT][1] = set_img(mlx, "./assets/character/walk/Walk_L_2.png");
	imgs.walk[LEFT][2] = set_img(mlx, "./assets/character/walk/Walk_L_3.png");
	imgs.walk[LEFT][3] = set_img(mlx, "./assets/character/walk/Walk_L_4.png");
	imgs.walk[LEFT][4] = set_img(mlx, "./assets/character/walk/Walk_L_5.png");
	imgs.walk[LEFT][5] = set_img(mlx, "./assets/character/walk/Walk_L_6.png");
	imgs.walk[LEFT][6] = set_img(mlx, "./assets/character/walk/Walk_L_7.png");
	imgs.walk[RIGHT][0] = set_img(mlx, "./assets/character/walk/Walk_R_1.png");
	imgs.walk[RIGHT][1] = set_img(mlx, "./assets/character/walk/Walk_R_2.png");
	imgs.walk[RIGHT][2] = set_img(mlx, "./assets/character/walk/Walk_R_3.png");
	imgs.walk[RIGHT][3] = set_img(mlx, "./assets/character/walk/Walk_R_4.png");
	imgs.walk[RIGHT][4] = set_img(mlx, "./assets/character/walk/Walk_R_5.png");
	imgs.walk[RIGHT][5] = set_img(mlx, "./assets/character/walk/Walk_R_6.png");
	imgs.walk[RIGHT][6] = set_img(mlx, "./assets/character/walk/Walk_R_7.png");
	printf("[finish init_asset]\n");
	return (imgs);
}

t_img	set_img(t_mlx mlx, char *filename)
{
	t_img	img;

	img.x = 32;
	img.y = 32;
	img.ptr = mlx_png_file_to_image(mlx.ptr, filename, &img.x, &img.y);
	printf("[finish set_img]\n");
	return (img);
}
