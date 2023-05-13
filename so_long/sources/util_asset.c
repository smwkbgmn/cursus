/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:52:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/13 14:42:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img		set_img(void *mlx, char *filename);
static t_img_char	set_img_char(void *mlx, char *prefix, t_uint cnt);
static t_bool		init_img_char(t_img_char *img_char, t_uint cnt);
static t_bool		assign_imgs(void *mlx, char *prefix, t_img_char *img_char);

t_asset	init_asset(void *mlx)
{
	t_asset	imgs;

	imgs.tile[0] = set_img(mlx, "assets/tile/empty.png");
	imgs.tile[1] = set_img(mlx, "assets/tile/tree.png");
	imgs.tile[2] = set_img(mlx, "assets/tile/exit.png");
	imgs.collect = set_img(mlx, "assets/object/collectible.png");
	imgs.player_walk = set_img_char(mlx, "./assets/character/player/Walk", 7);
	imgs.player_death = set_img_char(mlx,
			"./assets/character/player/Death", 10);
	imgs.enemy = set_img_char(mlx, "./assets/character/enemy/Walk", 14);
	return (imgs);
}

static t_img	set_img(void *mlx, char *filename)
{
	t_img	img;

	img.width = 32;
	img.height = 32;
	img.ptr = mlx_png_file_to_image(mlx, filename, &img.width, &img.height);
	// printf("set_img \"%s\"\n", filename);
	return (img);
}

static t_img_char	set_img_char(void *mlx, char *prefix, t_uint cnt)
{
	t_img_char	img_char;

	init_img_char(&img_char, cnt);
	assign_imgs(mlx, prefix, &img_char);
	return (img_char);
}

static t_bool	init_img_char(t_img_char *img_char, t_uint cnt)
{
	img_char->cut = malloc(sizeof(t_img *) * 2);
	img_char->cut[LEFT] = malloc(sizeof(t_img) * cnt);
	img_char->cut[RIGHT] = malloc(sizeof(t_img) * cnt);
	img_char->cnt_img = cnt;
	return (TRUE);
}

static t_bool	assign_imgs(void *mlx, char *prefix, t_img_char *img_char)
{
	char	*filename;
	t_uint	len_prefix;
	t_uint	len;
	t_uint	cnt;

	filename = ft_calloc(50, 1);
	len_prefix = ft_strlen(prefix);
	cnt = img_char->cnt_img;
	ft_strlcpy(filename, prefix, len_prefix + 1);
	while (cnt-- > 0)
	{
		len = len_prefix;
		len += ft_strlcat(&filename[len], "_L_", 4);
		len += ft_strlcat(&filename[len], ft_itoa(cnt + 1), 3);
		len += ft_strlcat(&filename[len], ".png", 5);
		img_char->cut[LEFT][cnt] = set_img(mlx, filename);
		filename[len_prefix + 1] = 'R';
		img_char->cut[RIGHT][cnt] = set_img(mlx, filename);
		ft_bzero(&filename[len_prefix], len - len_prefix);
	}
	free(filename);
	return (TRUE);
}
