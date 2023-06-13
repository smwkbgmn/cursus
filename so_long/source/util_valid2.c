/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:01:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/13 17:54:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool			find_exit(t_map map, t_list **checked, t_list **near, t_uint *cnt_clec);
void			assign_near(t_map map, t_list *checked, t_list **near, t_coord curnt);
t_bool			is_checked(t_list *checked, t_coord crd);
t_bool			is_listed(t_list *near, t_coord crd);
static t_bool	is_moveable(char tile);

t_uint	get_cnt_all_collecti(t_map map);

t_bool	check_valid_path(t_map map, t_coord curnt)
{
	static t_list	*checked;
	static t_list	*near;
	t_uint			cnt_clec;

	near = ft_lstnew(&curnt);
	return (find_exit(map, &checked, &near, &cnt_clec)
		&& cnt_clec == get_cnt_all_collecti(map));
}

t_bool	find_exit(t_map map, t_list **checked, t_list **near, t_uint *cnt_clec)
{
	static t_bool	valid_exit;
	t_list			*curnt;

	test_print_lists(*checked, *near, valid_exit);
	// curnt = *near;
	// if (ref_tile(map.map, *(t_coord *)curnt->content) == EXIT)
	// 	valid = TRUE;
	// else
	// {
	// 	*near = (*near)->next;
	// 	ft_lstadd_front(checked, curnt);
	// 	assign_near(map, *checked, near, *(t_coord *)curnt->content);
	// 	if (*near)
	// 		find_exit(map, checked, near);
	// }
	curnt = *near;
	if (ref_tile(map.map, *(t_coord *)curnt->content) == EXIT)
		valid_exit = TRUE;
	else if (ref_tile(map.map, *(t_coord *)curnt->content) == CLEC)
		(*cnt_clec)++;
	*near = (*near)->next;
	ft_lstadd_front(checked, curnt);
	if (ref_tile(map.map, *(t_coord *)curnt->content) != EXIT)
		assign_near(map, *checked, near, *(t_coord *)curnt->content);
	if (*near)
		find_exit(map, checked, near, cnt_clec);
	return (valid_exit);
	// return (cnt_clec == get_cnt_all_collecti(map) && valid_exit);
}

t_uint	get_cnt_all_collecti(t_map map)
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

void	assign_near(t_map map, t_list *checked, t_list **near, t_coord curnt)
{
	t_list	*node;
	t_coord	*crd;
	t_uint	cnt;

	cnt = 0;
	while (cnt < 4)
	{
		crd = malloc(sizeof(t_coord));
		if (crd)
		{
			crd->x = curnt.x - (cnt == 2) + (cnt == 3);
			crd->y = curnt.y - (cnt == 1) + (cnt == 0);
			if (is_moveable(map.map[crd->y][crd->x])
				&& !is_checked(checked, *crd)
				&& !is_listed(*near, *crd))
			{
				node = ft_lstnew(crd);
				if (node)
					ft_lstadd_front(near, node);
				else
				{
					ft_lstclear(near, &ft_free);
					ft_free(crd);
					break ;
				}
			}
			else
				ft_free(crd);
			cnt++;
		}
	}
}

t_bool	is_checked(t_list *checked, t_coord crd)
{
	while (checked)
	{
		if (((t_coord *)checked->content)->x == crd.x
			&& ((t_coord *)checked->content)->y == crd.y)
			return (TRUE);
		checked = checked->next;
	}
	return (FALSE);
}

t_bool	is_listed(t_list *near, t_coord crd)
{
	while (near)
	{
		if (((t_coord *)near->content)->x == crd.x
			&& ((t_coord *)near->content)->y == crd.y)
			return (TRUE);
		near = near->next;
	}
	return (FALSE);
}

static t_bool	is_moveable(char tile)
{
	return (tile != WALL && tile != ENMY);
}

//////////////////////////////////////////////////////////////////////////////

// t_bool	check_valid_path(t_map map, t_coord curnt)
// {
// 	static t_bool	valid;
// 	static t_list	*checked;
// 	t_list			*near;
// 	t_list			*go_to;

// 	ft_printf("current %d, %d / valid %d\n", curnt.x, curnt.y, valid);
// 	test_print_checked(checked);
// 	if (ref_tile(map.map, curnt) == EXIT)
// 		valid = TRUE;
// 	else
// 	{
// 		ft_lstadd_front(&checked, ft_lstnew(&curnt));
// 		near = get_list_near(map, checked, curnt);
// 		test_print_near(near);
// 		go_to = near;
// 		while (go_to && !valid)
// 		{
// 			check_valid_path(map, *(t_coord *)(go_to->content));
// 			go_to = go_to->next;
// 		}
// 		ft_lstclear(&near, &ft_free);
// 	}
// 	return (valid);
// }

// t_list	*get_list_near(t_map map, t_list *checked, t_coord curnt)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_coord	*crd;
// 	t_uint	cnt;

// 	list = NULL;
// 	cnt = 0;
// 	while (cnt < 4)
// 	{
// 		crd = malloc(sizeof(t_coord));
// 		if (crd)
// 		{
// 			crd->x = curnt.x - (cnt == 2) + (cnt == 3);
// 			crd->y = curnt.y - (cnt == 1) + (cnt == 0);
// 			if (is_moveable(map.map[crd->y][crd->x])
// 				&& !is_checked(checked, *crd))
// 			{
// 				node = ft_lstnew(crd);
// 				if (node)
// 					ft_lstadd_back(&list, node);
// 				else
// 				{
// 					ft_lstclear(&list, &ft_free);
// 					ft_free(crd);
// 					break ;
// 				}
// 			}
// 			else
// 				ft_free(crd);
// 			cnt++;
// 		}
// 	}
// 	return (list);
// }

// t_bool	is_checked(t_list *checked, t_coord crd)
// {
// 	while (checked)
// 	{
// 		if (((t_coord *)checked->content)->x == crd.x
// 			&& ((t_coord *)checked->content)->y == crd.y)
// 			return (TRUE);
// 		checked = checked->next;
// 	}
// 	return (FALSE);
// }

// static t_bool	is_moveable(char tile)
// {
// 	return (tile != WALL && tile != ENMY);
// }
