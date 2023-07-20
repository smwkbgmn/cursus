/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:49:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/20 01:53:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

void	set_img(void *mlx, t_img *img, char *name);
t_bool	init_img_char(t_img_char *img_char, t_uint cnt);
void	assign_imgs(void *mlx, char *prefix, t_img_char *img_char);
void	make_filename(char *name, char *pre, t_uint cnt, t_direc direction);

void	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt)
{
	if (init_img_char(img_char, cnt))
		assign_imgs(mlx, prefix, img_char);
}

t_bool	init_img_char(t_img_char *img_char, t_uint cnt)
{
	img_char->cut = malloc(sizeof(t_img *) * 2);
	if (img_char->cut)
	{
		img_char->cut[LEFT] = malloc(sizeof(t_img) * cnt);
		img_char->cut[RIGHT] = malloc(sizeof(t_img) * cnt);
		img_char->cnt_img = cnt;
		if (img_char->cut[LEFT] && img_char->cut[RIGHT])
		{
			while (cnt > 0)
			{
				img_char->cut[LEFT][cnt - 1].ptr = NULL;
				img_char->cut[RIGHT][cnt - 1].ptr = NULL;
				cnt--;
			}
			return (TRUE);
		}
	}
	return (FALSE);
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
	char	*number;

	ft_bzero(name, 50);
	len = ft_strlcat(name, pre, ft_strlen(pre) + 1);
	number = ft_itoa(cnt + 1);
	if (number)
	{
		if (direction == LEFT)
			len += ft_strlcat(name + len, "_L_", 4);
		else
			len += ft_strlcat(name + len, "_R_", 4);
		len += ft_strlcat(name + len, number, ft_strlen(number) + 1);
		ft_strlcat(name + len, ".png", 5);
		ft_free(number);
	}
}
