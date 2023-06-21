/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asset1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 20:21:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_img(void *mlx, char *filename);
t_bool	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt);

t_bool	init_asset(void *mlx, t_asset *imgs)
{
	t_bool	valid;

	valid = TRUE;
	imgs->tile[0] = set_img(mlx, "asset/tile/empty.png");
	imgs->tile[1] = set_img(mlx, "asset/tile/tree.png");
	imgs->tile[2] = set_img(mlx, "asset/tile/exit.png");
	imgs->collect = set_img(mlx, "asset/object/collectible.png");
	if (valid)
		valid = set_img_char(mlx, &imgs->player_walk,
				"./asset/character/player/Walk", 7);
	if (valid)
		valid = set_img_char(mlx, &imgs->player_death,
				"./asset/character/player/Death", 10);
	if (valid)
		valid = set_img_char(mlx, &imgs->enemy,
				"./asset/character/enemy/Walk", 14);
	return (valid);
}

t_img	set_img(void *mlx, char *filename)
{
	t_img	img;

	img.width = 32;
	img.height = 32;
	img.ptr = mlx_png_file_to_image(mlx, filename, &img.width, &img.height);
	return (img);
}
