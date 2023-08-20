/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:52:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:36:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, char *filename)
{
	init_map(&data->map, filename);
	valid_map(data->map);
	init_mlx(&data->map, &data->mlx);
	init_asset(data->mlx.ptr, &data->imgs);
	data->game = init_game(data->map);
	data->player = init_character(data->map, PLYR);
	data->enemy = init_character(data->map, ENMY);
}
