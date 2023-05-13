/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:52:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/13 15:02:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void);
t_mlx	init_mlx(t_map map);
t_game	init_game(t_map map);
t_char	init_character(t_map map, char target);
t_asset	init_asset(void *mlx);

t_bool	init_data(t_data *data)
{
	data->map = init_map();
	data->mlx = init_mlx(data->map);
	data->game = init_game(data->map);
	data->player = init_character(data->map, PLYR);
	data->enemy = init_character(data->map, ENMY);
	data->imgs = init_asset(data->mlx.ptr);
	return (TRUE);
}
