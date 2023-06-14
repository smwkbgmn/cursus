/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:14:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 20:35:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "so_long.h"

void	free_mlx(t_mlx *mlx);
void	free_char(t_img_char *imgs_char);

void	write_error(char *msg)
{
	write(2, "Error\n", 6);
	ft_printf("%s\n", msg);
}

void	free_data(t_data *data)
{
	free_mlx(&data->mlx);
	free_map(&data->map);
	free_char(&data->imgs.player_walk);
	free_char(&data->imgs.player_death);
	free_char(&data->imgs.enemy);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->ptr)
	{
		if (mlx->window)
			mlx_destroy_window(mlx->ptr, mlx->window);
		ft_free(mlx->ptr);
	}
}

void	free_map(t_map *map)
{
	if (map->map)
	{
		while (map->height-- > 0)
			ft_free(map->map[map->height]);
		ft_free(map->map);
	}
}

void	free_char(t_img_char *imgs_char)
{
	if (imgs_char->cut)
	{
		ft_free(imgs_char->cut[LEFT]);
		ft_free(imgs_char->cut[RIGHT]);
		ft_free(imgs_char->cut);
	}
}
