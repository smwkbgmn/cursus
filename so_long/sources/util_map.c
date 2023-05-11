/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/11 12:13:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.map = calloc(6, sizeof(char *));
	map.map[0] = strdup("11111111111111111111");
	map.map[1] = strdup("100000000000000000P1");
	map.map[2] = strdup("10000000000000000001");
	map.map[3] = strdup("1E0000000000000000C1");
	map.map[4] = strdup("11111111111111111111");
	map.map[5] = NULL;
	// map->dms = 32;
	map.width = 20;
	map.height = 5;
	// map.x_char = 18;
	// map.y_char = 1;
	return (map);
}
