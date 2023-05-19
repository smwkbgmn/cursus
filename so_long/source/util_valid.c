/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:03:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/18 19:40:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	valid_path(t_map map)
{
	t_coord	coord;
	t_list	*searched;
	t_list	*nearby;

	coord = find_player(map);
	searched = NULL;
	nearby = NULL;
	return (search(map, coord, &searched, &nearby));
}

t_bool	search(t_map map, t_coord coord, t_list **searched, t_list **nearby)
{
	if (ref_tile(map.map, coord) == PLYR)
		return (TRUE);
	else
	{
		ft_lstadd_back(searched, ft_lstnew(&map.map[coord.y][coord.x]));
		
	}
}

t_bool	is_searched(t_map map, t_uint x, t_uint y, t_list searched)
{
	char	*tile;

	tile = &map.map[y][x];ß
	
}

t_coord	find_player(t_map map)
{
	t_coord	start;
	char	*ptr_player;

	start.y = 0;
	while (start.y < map.height)
	{
		ptr_player = ft_strchr(map.map[start.y], PLYR);
		if (ptr_player)
			start.x = ptr_player - map.map[start.y];
		else
			start.y++;
	}
	return (start);
}
