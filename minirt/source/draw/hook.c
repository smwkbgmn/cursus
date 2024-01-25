/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:11:02 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 08:07:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	hookfn_key(int code, const t_render *data);
static int	hookfn_window_closed(const t_render *data);
static void	exit_program(const t_render *data);

void	activate_mlx(const t_render *data)
{
	mlx_key_hook(data->window.ptr, &hookfn_key, (void *)data);
	mlx_hook(data->window.ptr, ON_DESTROY, 0, &hookfn_window_closed, (void *)data);
	mlx_loop(data->window.mlx);
}

static int	hookfn_key(int key, const t_render *data)
{
	if (key == ESC)
		exit_program(data);
	return (NONE);
}

static int	hookfn_window_closed(const t_render *data) 
{
	exit_program(data);
	return (NONE);
}

static void	exit_program(const t_render *data)
{
	delete(data);
	exit(EXIT_SUCCESS);
}
