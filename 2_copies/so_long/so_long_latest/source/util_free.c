/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:14:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:34:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map);
void	free_asset(void *mlx, t_asset *imgs);
void	free_char(void *mlx, t_img_char *character);
void	free_img(void *mlx, void *ptr);

void	free_data(t_data *data)
{
	free_map(&data->map);
	if (data->mlx.ptr)
	{
		free_asset(data->mlx.ptr, &data->imgs);
		if (data->mlx.window)
			mlx_destroy_window(data->mlx.ptr, data->mlx.window);
	}
}

void	free_map(t_map *map)
{
	ft_printf("free map\n");
	if (map->map)
	{
		while (map->height-- > 0)
			ft_free(map->map[map->height]);
		ft_free(map->map);
	}
}

void	free_asset(void *mlx, t_asset *imgs)
{
	ft_printf("free asset\n");
	free_img(mlx, imgs->tile[0].ptr);
	free_img(mlx, imgs->tile[1].ptr);
	free_img(mlx, imgs->tile[2].ptr);
	free_img(mlx, imgs->collect.ptr);
	free_char(mlx, &imgs->player_walk);
	free_char(mlx, &imgs->player_death);
	free_char(mlx, &imgs->enemy);
}

void	free_char(void *mlx, t_img_char *character)
{
	t_uint	cnt;

	if (character->cut)
	{
		cnt = 0;
		while (cnt < character->cnt_img)
		{
			if (character->cut[LEFT])
				free_img(mlx, character->cut[LEFT][cnt].ptr);
			if (character->cut[RIGHT])
				free_img(mlx, character->cut[RIGHT][cnt].ptr);
			cnt++;
		}
		ft_free(character->cut[LEFT]);
		ft_free(character->cut[RIGHT]);
	}
	ft_free(character->cut);
}

void	free_img(void *mlx, void *ptr)
{
	ft_printf("freeing %p\n", ptr);
	if (ptr)
		mlx_destroy_image(mlx, ptr);
}
