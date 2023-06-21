/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_dfs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:01:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/21 15:39:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_map map, t_dfs *dfs, t_bool *valid, t_uint *collected);
void	check_tile(char tile, t_bool *valid, t_uint *collected);
void	adjust_dfs(t_dfs *dfs, t_list *current);
t_bool	assign_near(t_map map, t_dfs *dfs, t_coord curnt);
t_coord	*get_coord(t_uint x, t_uint y);
t_bool	add_to_stack(t_map map, t_dfs *dfs, t_coord *crd);
t_uint	get_cnt_all_clec(t_map map);

t_bool	check_valid_path(t_map map, t_coord start)
{
	static t_dfs	dfs;
	t_bool			valid;
	t_uint			collected;
	t_coord			*ptr_start;

	valid = FALSE;
	ptr_start = get_coord(start.x, start.y);
	if (ptr_start)
	{
		if (add_to_stack(map, &dfs, ptr_start))
		{
			collected = 0;
			find_exit(map, &dfs, &valid, &collected);
			ft_lstclear(&dfs.checked, &ft_free);
			ft_lstclear(&dfs.stack, &ft_free);
		}
		else
			ft_free(ptr_start);
	}
	if (!(valid && collected == get_cnt_all_clec(map)))
		write_error("PATH TO EXIT IS NOT VALID");
	return (valid && collected == get_cnt_all_clec(map));
}

void	find_exit(t_map map, t_dfs *dfs, t_bool *valid, t_uint *collected)
{
	t_list			*current;
	char			tile;

	current = dfs->stack;
	tile = ref_tile(map.map, ref_coord(current));
	check_tile(tile, valid, collected);
	adjust_dfs(dfs, current);
	if (tile != EXIT)
	{
		if (!assign_near(map, dfs, ref_coord(current)))
		{
			*valid = FALSE;
			return ;
		}
	}
	if (dfs->stack)
		find_exit(map, dfs, valid, collected);
}

void	check_tile(char tile, t_bool *valid, t_uint *collected)
{
	if (tile == EXIT)
		*valid = TRUE;
	else if (tile == CLEC)
		(*collected)++;
}

void	adjust_dfs(t_dfs *dfs, t_list *current)
{
	dfs->stack = dfs->stack->next;
	ft_lstadd_front(&dfs->checked, current);
}

t_bool	assign_near(t_map map, t_dfs *dfs, t_coord curnt)
{
	t_bool	valid;
	t_coord	*crd;
	t_uint	cnt;

	cnt = 0;
	while (cnt < 4 && valid)
	{
		crd = get_coord(curnt.x - (cnt == 2) + (cnt == 3),
				curnt.y - (cnt == 1) + (cnt == 0));
		if (crd)
			valid = add_to_stack(map, dfs, crd);
		else
			valid = FALSE;
		cnt++;
	}
	return (valid);
}
