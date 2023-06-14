/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:49:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 20:59:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_img		set_img(void *mlx, char *filename);
t_bool		init_img_char(t_img_char *img_char, t_uint cnt);
t_bool		assign_imgs(void *mlx, char *prefix, t_img_char *img_char);
void		make_filename(char *filename, t_uint *len, t_uint cnt);

t_bool	set_img_char(void *mlx, t_img_char *img_char, char *prefix, t_uint cnt)
{
	if (init_img_char(img_char, cnt))
		return (assign_imgs(mlx, prefix, img_char));
	else
		return (FALSE);
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
			return (TRUE);
	}
	return (FALSE);
}

t_bool	assign_imgs(void *mlx, char *prefix, t_img_char *img_char)
{
	char	*filename;
	t_uint	len_prefix;
	t_uint	len;
	t_uint	cnt;

	filename = ft_calloc(50, 1);
	if (filename)
	{
		len_prefix = ft_strlen(prefix);
		cnt = img_char->cnt_img;
		ft_strlcpy(filename, prefix, len_prefix + 1);
		while (cnt-- > 0)
		{
			len = len_prefix;
			make_filename(filename, &len, cnt);
			img_char->cut[LEFT][cnt] = set_img(mlx, filename);
			filename[len_prefix + 1] = 'R';
			img_char->cut[RIGHT][cnt] = set_img(mlx, filename);
			ft_bzero(&filename[len_prefix], len - len_prefix);
		}
		free(filename);
		return (TRUE);
	}
	return (FALSE);
}

void	make_filename(char *filename, t_uint *len, t_uint cnt)
{
	*len += ft_strlcat(&filename[*len], "_L_", 4);
	*len += ft_strlcat(&filename[*len], ft_itoa(cnt + 1), 3);
	*len += ft_strlcat(&filename[*len], ".png", 5);
}
