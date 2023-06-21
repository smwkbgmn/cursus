/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:28:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 18:44:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "so_long.h"

t_bool	is_checked(t_list *checked, t_coord crd);
t_bool	is_listed(t_list *near, t_coord crd);
t_bool	is_moveable(t_map map, t_coord move);

t_coord	*get_coord(t_uint x, t_uint y)
{
	t_coord	*new;

	new = malloc(sizeof(t_coord));
	if (new)
	{
		new->x = x;
		new->y = y;
	}
	return (new);
}

t_bool	add_to_stack(t_map map, t_dfs *dfs, t_coord *crd)
{
	t_list	*node;

	if (is_moveable(map, *crd)
		&& !is_checked(dfs->checked, *crd) && !is_listed(dfs->stack, *crd))
	{
		node = ft_lstnew(crd);
		if (node)
		{
			ft_lstadd_front(&dfs->stack, node);
			return (TRUE);
		}
		else
		{
			ft_free(crd);
			ft_lstclear(&dfs->stack, &ft_free);
			return (FALSE);
		}
	}
	else
	{
		ft_free(crd);
		return (TRUE);
	}
}

t_uint	get_cnt_all_clec(t_map map)
{
	t_uint	cnt_clec;
	t_coord	crd;

	cnt_clec = 0;
	crd.y = 0;
	while (crd.y < map.height)
	{
		crd.x = 0;
		while (crd.x < map.width)
		{
			if (ref_tile(map.map, crd) == CLEC)
				cnt_clec++;
			crd.x++;
		}
		crd.y++;
	}
	return (cnt_clec);
}
