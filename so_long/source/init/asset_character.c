/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:49:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:33:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

void	init_img_char(t_img_char *img_char, t_uint cnt);
void	assign_imgs(void *mlx, char *prefix, t_img_char *img_char);
void	make_filename(char *name, char *pre, t_uint cnt, t_direc direction);
t_uint	append_number(char *name, char *str_num);

void	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt)
{
	init_img_char(img_char, cnt);
	assign_imgs(mlx, prefix, img_char);
}

void	init_img_char(t_img_char *img_char, t_uint cnt)
{
	img_char->cut = catcher(malloc(sizeof(t_img *) * 2));
	img_char->cut[LEFT] = catcher(malloc(sizeof(t_img) * cnt));
	img_char->cut[RIGHT] = catcher(malloc(sizeof(t_img) * cnt));
	img_char->cnt_img = cnt;
}

void	assign_imgs(void *mlx, char *prefix, t_img_char *img_char)
{
	char	name[50];
	t_uint	cnt;

	cnt = 0;
	while (cnt < img_char->cnt_img)
	{
		make_filename(name, prefix, cnt, LEFT);
		set_img(mlx, &img_char->cut[LEFT][cnt], name);
		make_filename(name, prefix, cnt, RIGHT);
		set_img(mlx, &img_char->cut[RIGHT][cnt], name);
		cnt++;
	}

}

void	make_filename(char *name, char *pre, t_uint cnt, t_direc direction)
{
	t_uint	len;

	ft_bzero(name, 50);
	len = ft_strlcat(name, pre, ft_strlen(pre) + 1);
	if (direction == LEFT)
		len += ft_strlcat(name + len, "_L_", 4);
	else
		len += ft_strlcat(name + len, "_R_", 4);
	len += append_number(name + len, catcher(ft_itoa(cnt + 1)));
	ft_strlcat(name + len, ".png", 5);
}

t_uint	append_number(char *name, char *str_num)
{
	t_uint	len;

	len = ft_strlcat(name, str_num, ft_strlen(str_num) + 1);
	ft_free(str_num);
	return (len);
}
