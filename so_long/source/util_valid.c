/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:03:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/23 01:32:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_bool	valid_path(t_map map)
// {
// 	t_coord	crd;
// 	t_bool	**visit;
// 	t_coord	*stack;

// 	crd = find_player(map);
// 	visit = init_visit(map);
// 	stack = ft_calloc(map.width * map.height, sizeof(t_coord));
// 	return (TRUE)
// }

// t_bool	search(t_map map, t_coord coord, )
// {
// 	if (ref_tile(map.map, coord) == EXIT)
// 		return (TRUE);
// 	else
// 	{
// 		assign_nearby(map, coord, visit, stack);
// 	}
// }

// void	assign_nearby(t_map map, t_coord coord, t_list *visit, t_list *stack)
// {
	
// }

// t_bool	**init_visit(t_map map)
// {
// 	t_bool	**visit;
// 	t_uint	ptr;

// 	visit = ft_calloc(map.height, sizeof(t_bool *));
// 	ptr = 0;
// 	while (ptr < map.height)
// 		visit[ptr++] = ft_calloc(map.width, sizeof(t_bool));
// }

// t_coord	find_player(t_map map)
// {
// 	t_coord	start;
// 	char	*ptr_player;

// 	start.y = 0;
// 	while (start.y < map.height)
// 	{
// 		ptr_player = ft_strchr(map.map[start.y], PLYR);
// 		if (ptr_player)
// 			start.x = ptr_player - map.map[start.y];
// 		else
// 			start.y++;
// 	}
// 	return (start);
// }
