/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:03:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/13 17:56:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_start_exit_collectie(t_map map);
t_bool	check_surround_with_wall(t_map map);

t_bool	valid_map(t_map map)
{
	if (map.map)
		return (check_start_exit_collectie(map)
			&& check_surround_with_wall(map)
			&& check_valid_path(map, get_coord_target(map, PLYR)));
	else
		return (FALSE);
}

t_bool	check_start_exit_collectie(t_map map)
{
	static t_uint	start;
	static t_uint	exit;
	static t_uint	collect;
	t_coord			crd;

	crd.y = 0;
	while (crd.y < map.height)
	{
		crd.x = 0;
		while (crd.x < map.width)
		{
			start += (ref_tile(map.map, crd) == PLYR);
			exit += (ref_tile(map.map, crd) == EXIT);
			collect += (ref_tile(map.map, crd) == CLEC);
			crd.x++;
		}
		crd.y++;
	}
	ft_printf("start : %d\nexit : %d\nclec : %d\n", start, exit, collect);
	return (start == 1 && exit == 1 && collect > 0);
}

t_bool	check_surround_with_wall(t_map map)
{
	static t_bool	valid;
	t_coord			crd;

	valid = TRUE;
	crd.y = 0;
	while (crd.y < map.height && valid)
	{
		if (crd.y == 0 || crd.y == map.height - 1)
		{
			crd.x = 0;
			while (crd.x < map.width && valid)
			{
				valid = (ref_tile(map.map, crd) == WALL);
				crd.x++;
			}
		}
		else
		{
			valid = (map.map[crd.y][0] == WALL
					&& map.map[crd.y][map.width - 1] == WALL);
		}
		crd.y++;
	}
	ft_printf("surround valid : %d\n", valid);
	return (valid);
}
