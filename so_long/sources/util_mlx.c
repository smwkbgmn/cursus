/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:32:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/09 17:54:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	init_mlx(t_map map)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, map.x * 32, map.y * 32, "new");
	return (mlx);
}
