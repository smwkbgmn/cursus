/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:58:15 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 18:53:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	ref_coord(t_list *node)
{
	return (*(t_coord *)node->content);
}

t_bool	is_checked(t_list *checked, t_coord crd)
{
	while (checked)
	{
		if (ref_coord(checked).x == crd.x
			&& ref_coord(checked).y == crd.y)
			return (TRUE);
		checked = checked->next;
	}
	return (FALSE);
}

t_bool	is_listed(t_list *near, t_coord crd)
{
	while (near)
	{
		if (ref_coord(near).x == crd.x
			&& ref_coord(near).y == crd.y)
			return (TRUE);
		near = near->next;
	}
	return (FALSE);
}

t_bool	is_moveable(t_map map, t_coord move)
{
	t_bool	valid;
	char	tile;
	t_coord	near;
	t_uint	cnt;

	tile = map.map[move.y][move.x];
	if (tile != WALL && tile != ENMY)
	{
		cnt = 0;
		valid = TRUE;
		while (cnt < 4 && valid)
		{
			near.x = move.x - (cnt == 2) + (cnt == 3);
			near.y = move.y - (cnt == 1) + (cnt == 0);
			if (map.map[near.y][near.x] == ENMY)
				valid = FALSE;
			cnt++;
		}
	}
	else
		valid = FALSE;
	return (valid);
}
