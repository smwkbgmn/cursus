/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 15:06:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "so_long.h"

t_map	init_map(char *filename)
{
	t_map	map;

	// map.map = ft_calloc(6, sizeof(char *));
	// // map.map[0] = ft_strdup("11111111111111111111");
	// // map.map[1] = ft_strdup("100000000010000000P1");
	// // map.map[2] = ft_strdup("100000000M0000000001");
	// // map.map[3] = ft_strdup("1E0000000000000000C1");
	// // map.map[4] = ft_strdup("11111111111111111111");
	// map.map[0] = ft_strdup("11111111111111111111");
	// map.map[1] = ft_strdup("1CCCCCCCC01CCCCCCCP1");
	// map.map[2] = ft_strdup("1CCCCCC10M0CCCCCCCC1");
	// map.map[3] = ft_strdup("1ECCCCCCCCCCCCCCCCC1");
	// map.map[4] = ft_strdup("11111111111111111111");
	// map.map[5] = NULL;
	// map.width = 20;
	// map.height = 5;
	return (map);
}

char	ref_tile(char **map, t_coord coord)
{
	return (map[coord.y][coord.x]);
}

void	swap_tile(char **map, t_char *chartr, t_coord moved, char target)
{
	map[chartr->coord.y][chartr->coord.x] = EMTY;
	map[moved.y][moved.x] = target;
	chartr->coord = moved;
}

// t_bool	valid_map()
