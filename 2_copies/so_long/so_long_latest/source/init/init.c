/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:52:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:17:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>

t_bool	init_map(t_map *map, char *filename);
t_bool	valid_map(t_map map);
t_bool	init_mlx(t_map *map, t_mlx *mlx);
t_bool	init_asset(void *mlx, t_asset *imgs);
t_game	init_game(t_map map);
t_char	init_character(t_map map, char target);

t_bool	init_data(t_data *data, char *filename)
{
	if (init_map(&data->map, filename) && valid_map(data->map))
	{
		if (init_mlx(&data->map, &data->mlx)
			&& init_asset(data->mlx.ptr, &data->imgs))
		{
			data->game = init_game(data->map);
			data->player = init_character(data->map, PLYR);
			data->enemy = init_character(data->map, ENMY);
			return (TRUE);
		}
		else
			free_data(data);
	}
	else
		free_map(&data->map);
	return (FALSE);
}
