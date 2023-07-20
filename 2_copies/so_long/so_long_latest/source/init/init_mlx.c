/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:32:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:15:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	init_mlx(t_map *map, t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (mlx)
	{
		mlx->window = mlx_new_window(mlx->ptr,
				map->width * 32, map->height * 32, "so_long");
		if (mlx->window)
			return (TRUE);
	}
	return (FALSE);
}
