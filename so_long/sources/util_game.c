/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/10 02:01:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_game	init_game(char **map)
{
	t_game	player;
	t_uint	ptr;
	t_uint	idx;

	ptr = 0;
	player.collected = 0;
	player.goal = 0;
	while (ptr < 5)
	{
		idx = 0;
		while (idx < 20)
		{
			if (map[ptr][idx] == PLYR)
			{
				player.x = idx;
				player.y = ptr;
			}
			else if (map[ptr][idx] == CLEC)
				player.goal++;
			idx++;
		}
		ptr++;
	}
	return (player);
}
