/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:41:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void);
t_mlx	init_mlx(t_map map);
t_asset	init_asset(t_mlx mlx);
t_game	init_game(char **map);

int		key_hook(int keycode, t_data *data);
int		write_frame(t_data *data);
// int		check_exit(t_data *data);
// int		close(t_data *data);

int	main(void)
{
	t_data	data;

	data.map = init_map();
	data.mlx = init_mlx(data.map);
	data.imgs = init_asset(data.mlx);
	data.player = init_game(data.map.map);

	mlx_key_hook(data.mlx.window, key_hook, &data);
	mlx_loop_hook(data.mlx.ptr, write_frame, &data);
	// mlx_loop_hook(data.mlx.ptr, check_exit, &data);
	// mlx_hook(data.mlx.window, ON_DESTROY, 0, close, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}

int	check_exit(t_data *data)
{
	if (data->player.collected == data->player.goal)
	{
		mlx_destroy_window(data->mlx.ptr, data->mlx.window);
		// exit(0);
		// return (TRUE);
	}
	// else
	// 	return (FALSE);
	return (0);
	// return (data->player.collected == data->player.goal);
}

int	close(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.window);
	return (0);
}
