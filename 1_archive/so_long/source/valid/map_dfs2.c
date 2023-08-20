/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_dfs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:06:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:25:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_on_list(t_list *list, t_coord crd);
static t_bool	is_moveable(t_map map, t_coord to_move);
static t_bool	is_enemy(t_coord enmy, t_uint x, t_uint y);

void	add_nearby(t_dfs *dfs, t_map map, t_coord curnt)
{
	t_list	*next;
	t_coord	near;
	t_uint	cnt;

	cnt = 0;
	while (cnt < 4)
	{
		near.x = curnt.x + (cnt == 3) - (cnt == 2);
		near.y = curnt.y + (cnt == 0) - (cnt == 1);
		if (is_moveable(map, near)
			&& !is_on_list(dfs->checked, near)
			&& !is_on_list(dfs->stack, near))
		{
			next = catcher(ft_lstnew(new_coord(near)));
			ft_lstadd_back(&dfs->stack, next);
		}
		else if (ref_tile(map.map, near) == EXIT)
			dfs->meet_exit = TRUE;
		cnt++;
	}
}

static t_bool	is_on_list(t_list *list, t_coord crd)
{
	t_coord	*ref;

	while (list)
	{
		ref = list->content;
		if (ref->x == crd.x && ref->y == crd.y)
			return (TRUE);
		else
			list = list->next;
	}
	return (FALSE);
}

static t_bool	is_moveable(t_map map, t_coord to_move)
{
	char	tile;

	tile = ref_tile(map.map, to_move);
	if (tile == EMTY || tile == CLEC)
		return (!is_nearby_enemy(map, to_move));
	else
		return (FALSE);
}

t_bool	is_nearby_enemy(t_map map, t_coord plyr)
{
	t_coord	enmy;

	enmy = get_coord_target(map, ENMY);
	return (is_enemy(enmy, plyr.x + 1, plyr.y)
		|| is_enemy(enmy, plyr.x - 1, plyr.y)
		|| is_enemy(enmy, plyr.x, plyr.y + 1)
		|| is_enemy(enmy, plyr.x, plyr.y - 1));
}

static t_bool	is_enemy(t_coord enmy, t_uint x, t_uint y)
{
	return (x == enmy.x && y == enmy.y);
}
