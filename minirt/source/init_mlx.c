/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:09:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/11/03 14:34:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		err_usr("error: mlx_init");
	mlx->win = mlx_new_window(mlx->ptr, 1280, 920, "minirt");
	if (!mlx->win)
		err_usr("error: mlx_new_window");
}
