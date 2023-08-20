/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_dfs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:12:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:55:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_dfs(t_dfs *dfs, t_map map, t_coord start);
static void	check_tile(t_dfs *dfs, t_map map);
static void	adjust_dfs(t_dfs *dfs, t_map map, t_coord crd);
static void	free_dfs(t_dfs *dfs);

void	check_valid_path(t_map map)
{
	static t_dfs	dfs;

	init_dfs(&dfs, map, get_coord_target(map, PLYR));
	check_tile(&dfs, map);
	if (!dfs.meet_exit || dfs.cnt_collect != game_goal(map))
	{
		write_error("NO VALID PATH");
		exit_with_error(NULL);
	}
	free_dfs(&dfs);
}

static void	init_dfs(t_dfs *dfs, t_map map, t_coord start)
{
	if (!is_nearby_enemy(map, start))
		add_nearby(dfs, map, start);
}

static void	check_tile(t_dfs *dfs, t_map map)
{
	t_coord	*crd;

	if (dfs->stack)
	{
		crd = dfs->stack->content;
		if (ref_tile(map.map, *crd) == CLEC)
			dfs->cnt_collect++;
		adjust_dfs(dfs, map, *crd);
		check_tile(dfs, map);
	}
}

static void	adjust_dfs(t_dfs *dfs, t_map map, t_coord crd)
{
	t_list	*checked;

	checked = dfs->stack;
	dfs->stack = dfs->stack->next;
	checked->next = NULL;
	ft_lstadd_back(&dfs->checked, checked);
	add_nearby(dfs, map, crd);
}

static void	free_dfs(t_dfs *dfs)
{
	ft_lstclear(&dfs->checked, &ft_free);
	ft_lstclear(&dfs->stack, &ft_free);
}
