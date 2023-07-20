/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:15 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 20:54:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	ref_coord(t_list *node)
{
	return (*(t_coord *)node->content);
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
