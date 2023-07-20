/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:20:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(void *mlx, t_img *img, char *name);
void	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt);
t_bool	check_all_ptr(t_asset *imgs);
t_bool	check_ptrs(t_img_char *character);

t_bool	init_asset(void *mlx, t_asset *imgs)
{
	set_img(mlx, &imgs->tile[0], "asset/tile/empty.png");
	set_img(mlx, &imgs->tile[1], "asset/tile/tree.png");
	set_img(mlx, &imgs->tile[2], "asset/tile/exit.png");
	set_img(mlx, &imgs->collect, "asset/object/collectible.png");
	set_img_char(mlx, &imgs->player_walk, "asset/character/player/Walk", 7);
	set_img_char(mlx, &imgs->player_death, "asset/character/player/Death", 10);
	set_img_char(mlx, &imgs->enemy, "asset/character/enemy/Walk", 14);
	return (check_all_ptr(imgs));
}

void	set_img(void *mlx, t_img *img, char *name)
{
	img->width = 32;
	img->height = 32;
	img->ptr = mlx_png_file_to_image(mlx, name, &img->width, &img->height);
	ft_printf("assigned %p\n", img->ptr);
}

t_bool	check_all_ptr(t_asset *imgs)
{
	t_bool	valid;

	valid = TRUE;
	valid = (valid && imgs->tile[0].ptr);
	valid = (valid && imgs->tile[1].ptr);
	valid = (valid && imgs->tile[2].ptr);
	valid = (valid && imgs->collect.ptr);
	valid = (valid && check_ptrs(&imgs->player_walk));
	valid = (valid && check_ptrs(&imgs->player_death));
	valid = (valid && check_ptrs(&imgs->enemy));
	return (valid);
}

t_bool	check_ptrs(t_img_char *character)
{
	t_bool	valid;
	t_uint	cnt;

	valid = TRUE;
	cnt = 0;
	while (cnt < character->cnt_img)
	{
		valid = (valid && character->cut[LEFT][cnt].ptr);
		valid = (valid && character->cut[RIGHT][cnt].ptr);
		cnt++;
	}
	return (valid);
}
