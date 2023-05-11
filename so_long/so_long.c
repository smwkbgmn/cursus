/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/12 02:14:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void);
t_mlx	init_mlx(t_map map);
t_game	init_game(t_map map);
t_char	init_character(t_map map, char target);
t_asset	init_asset(t_mlx mlx);

int		move_character(int keycode, t_data *data);
int		write_frame(t_data *data);
int		check_window_close(t_data *data);

int	main(void)
{
	t_data	data;

	data.map = init_map();
	data.mlx = init_mlx(data.map);
	data.game = init_game(data.map);
	data.player = init_character(data.map, PLYR);
	data.enemy = init_character(data.map, ENMY);
	data.imgs = init_asset(data.mlx);

	mlx_loop_hook(data.mlx.ptr, write_frame, &data);
	// mlx_key_hook(data.mlx.window, key_hook, &data);
	mlx_key_hook(data.mlx.window, move_character, &data);
	mlx_hook(data.mlx.window, ON_DESTROY, 0, check_window_close, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}

int	check_window_close(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.window);
	exit(0);
	return (0);
}
