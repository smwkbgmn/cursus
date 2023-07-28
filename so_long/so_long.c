/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 20:06:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_data	data;

	if (ac == 2)
	{
		init_data(&data, *(av + 1));
		mlx_hook(data.mlx.window, ON_DESTROY, 0, window_closed, &data);
		mlx_key_hook(data.mlx.window, key_hook, &data);
		mlx_loop_hook(data.mlx.ptr, loop_hook, &data);
		mlx_loop(data.mlx.ptr);
	}
	return (0);
}
