/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:31:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:35:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_char	init_character(t_map map, char target)
{
	t_char	chartr;

	chartr.frame = 0;
	chartr.coord = get_coord_target(map, target);
	if (chartr.coord.x < map.width / 2)
		chartr.direction = RIGHT;
	else
		chartr.direction = LEFT;
	chartr.move = 0;
	chartr.death = FALSE;
	return (chartr);
}

t_coord	get_coord_target(t_map map, char target)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < map.height)
	{
		coord.x = 0;
		while (coord.x < map.width)
		{
			if (ref_tile(map.map, coord) == target)
				return (coord);
			coord.x++;
		}
		coord.y++;
	}
	return (coord);
}
