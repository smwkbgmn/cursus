/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_dfs3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:06:04 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:22:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_coord	*new_coord(t_coord crd)
{
	t_coord	*new;

	new = catcher(malloc(sizeof(t_coord) * 1));
	new->x = crd.x;
	new->y = crd.y;
	return (new);
}

t_uint	game_goal(t_map map)
{
	t_uint	cnt;
	t_coord	crd;

	cnt = 0;
	crd.y = 0;
	while (crd.y < map.height)
	{
		crd.x = 0;
		while (crd.x < map.width)
		{
			if (ref_tile(map.map, crd) == CLEC)
				cnt++;
			crd.x++;
		}
		crd.y++;
	}
	return (cnt);
}
