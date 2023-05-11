/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 02:17:13 by donghyu2         ###   ########.fr       */
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

	imgs.player_walk[LEFT][0] = set_img(mlx, "./assets/character/player/Walk_L_1.png");
	imgs.player_walk[LEFT][1] = set_img(mlx, "./assets/character/player/Walk_L_2.png");
	imgs.player_walk[LEFT][2] = set_img(mlx, "./assets/character/player/Walk_L_3.png");
	imgs.player_walk[LEFT][3] = set_img(mlx, "./assets/character/player/Walk_L_4.png");
	imgs.player_walk[LEFT][4] = set_img(mlx, "./assets/character/player/Walk_L_5.png");
	imgs.player_walk[LEFT][5] = set_img(mlx, "./assets/character/player/Walk_L_6.png");
	imgs.player_walk[LEFT][6] = set_img(mlx, "./assets/character/player/Walk_L_7.png");
	imgs.player_walk[RIGHT][0] = set_img(mlx, "./assets/character/player/Walk_R_1.png");
	imgs.player_walk[RIGHT][1] = set_img(mlx, "./assets/character/player/Walk_R_2.png");
	imgs.player_walk[RIGHT][2] = set_img(mlx, "./assets/character/player/Walk_R_3.png");
	imgs.player_walk[RIGHT][3] = set_img(mlx, "./assets/character/player/Walk_R_4.png");
	imgs.player_walk[RIGHT][4] = set_img(mlx, "./assets/character/player/Walk_R_5.png");
	imgs.player_walk[RIGHT][5] = set_img(mlx, "./assets/character/player/Walk_R_6.png");
	imgs.player_walk[RIGHT][6] = set_img(mlx, "./assets/character/player/Walk_R_7.png");

	imgs.player_death[LEFT][0] = set_img(mlx, "./assets/character/player/Death_L_1.png");
	imgs.player_death[LEFT][1] = set_img(mlx, "./assets/character/player/Death_L_2.png");
	imgs.player_death[LEFT][2] = set_img(mlx, "./assets/character/player/Death_L_3.png");
	imgs.player_death[LEFT][3] = set_img(mlx, "./assets/character/player/Death_L_4.png");
	imgs.player_death[LEFT][4] = set_img(mlx, "./assets/character/player/Death_L_5.png");
	imgs.player_death[LEFT][5] = set_img(mlx, "./assets/character/player/Death_L_6.png");
	imgs.player_death[LEFT][6] = set_img(mlx, "./assets/character/player/Death_L_7.png");
	imgs.player_death[LEFT][7] = set_img(mlx, "./assets/character/player/Death_L_8.png");
	imgs.player_death[LEFT][8] = set_img(mlx, "./assets/character/player/Death_L_9.png");
	imgs.player_death[LEFT][9] = set_img(mlx, "./assets/character/player/Death_L_10.png");
	imgs.player_death[RIGHT][0] = set_img(mlx, "./assets/character/player/Death_R_1.png");
	imgs.player_death[RIGHT][1] = set_img(mlx, "./assets/character/player/Death_R_2.png");
	imgs.player_death[RIGHT][2] = set_img(mlx, "./assets/character/player/Death_R_3.png");
	imgs.player_death[RIGHT][3] = set_img(mlx, "./assets/character/player/Death_R_4.png");
	imgs.player_death[RIGHT][4] = set_img(mlx, "./assets/character/player/Death_R_5.png");
	imgs.player_death[RIGHT][5] = set_img(mlx, "./assets/character/player/Death_R_6.png");
	imgs.player_death[RIGHT][6] = set_img(mlx, "./assets/character/player/Death_R_7.png");
	imgs.player_death[RIGHT][7] = set_img(mlx, "./assets/character/player/Death_R_8.png");
	imgs.player_death[RIGHT][8] = set_img(mlx, "./assets/character/player/Death_R_9.png");
	imgs.player_death[RIGHT][9] = set_img(mlx, "./assets/character/player/Death_R_10.png");

	imgs.enemy[LEFT][0] = set_img(mlx, "./assets/character/enemy/Walk_L_1.png");
	imgs.enemy[LEFT][1] = set_img(mlx, "./assets/character/enemy/Walk_L_2.png");
	imgs.enemy[LEFT][2] = set_img(mlx, "./assets/character/enemy/Walk_L_3.png");
	imgs.enemy[LEFT][3] = set_img(mlx, "./assets/character/enemy/Walk_L_4.png");
	imgs.enemy[LEFT][4] = set_img(mlx, "./assets/character/enemy/Walk_L_5.png");
	imgs.enemy[LEFT][5] = set_img(mlx, "./assets/character/enemy/Walk_L_6.png");
	imgs.enemy[LEFT][6] = set_img(mlx, "./assets/character/enemy/Walk_L_7.png");
	imgs.enemy[LEFT][7] = set_img(mlx, "./assets/character/enemy/Walk_L_8.png");
	imgs.enemy[LEFT][8] = set_img(mlx, "./assets/character/enemy/Walk_L_9.png");
	imgs.enemy[LEFT][9] = set_img(mlx, "./assets/character/enemy/Walk_L_10.png");
	imgs.enemy[LEFT][10] = set_img(mlx, "./assets/character/enemy/Walk_L_11.png");
	imgs.enemy[LEFT][11] = set_img(mlx, "./assets/character/enemy/Walk_L_12.png");
	imgs.enemy[LEFT][12] = set_img(mlx, "./assets/character/enemy/Walk_L_13.png");
	imgs.enemy[LEFT][13] = set_img(mlx, "./assets/character/enemy/Walk_L_14.png");
	imgs.enemy[RIGHT][0] = set_img(mlx, "./assets/character/enemy/Walk_R_1.png");
	imgs.enemy[RIGHT][1] = set_img(mlx, "./assets/character/enemy/Walk_R_2.png");
	imgs.enemy[RIGHT][2] = set_img(mlx, "./assets/character/enemy/Walk_R_3.png");
	imgs.enemy[RIGHT][3] = set_img(mlx, "./assets/character/enemy/Walk_R_4.png");
	imgs.enemy[RIGHT][4] = set_img(mlx, "./assets/character/enemy/Walk_R_5.png");
	imgs.enemy[RIGHT][5] = set_img(mlx, "./assets/character/enemy/Walk_R_6.png");
	imgs.enemy[RIGHT][6] = set_img(mlx, "./assets/character/enemy/Walk_R_7.png");
	imgs.enemy[RIGHT][7] = set_img(mlx, "./assets/character/enemy/Walk_R_8.png");
	imgs.enemy[RIGHT][8] = set_img(mlx, "./assets/character/enemy/Walk_R_9.png");
	imgs.enemy[RIGHT][9] = set_img(mlx, "./assets/character/enemy/Walk_R_10.png");
	imgs.enemy[RIGHT][10] = set_img(mlx, "./assets/character/enemy/Walk_R_11.png");
	imgs.enemy[RIGHT][11] = set_img(mlx, "./assets/character/enemy/Walk_R_12.png");
	imgs.enemy[RIGHT][12] = set_img(mlx, "./assets/character/enemy/Walk_R_13.png");
	imgs.enemy[RIGHT][13] = set_img(mlx, "./assets/character/enemy/Walk_R_14.png");
	printf("[finish init_asset]\n");
	return (imgs);
}

t_img	set_img(t_mlx mlx, char *filename)
{
	t_img	img;

	img.width = 32;
	img.height = 32;
	img.ptr = mlx_png_file_to_image(mlx.ptr, filename, &img.width, &img.height);
	printf("[finish set_img]\n");
	return (img);
}
