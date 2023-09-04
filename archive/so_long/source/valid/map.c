/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:03:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/29 04:02:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_start_exit_collectie(t_map map);
static void	check_enemy(t_map map);
static void	check_surround_with_wall(t_map map);
static void	check_wall(char *line, t_uint width, t_bool is_middle);

void	valid_map(t_map map)
{
	check_start_exit_collectie(map);
	check_enemy(map);
	check_surround_with_wall(map);
	check_valid_path(map);
}

static void	check_start_exit_collectie(t_map map)
{
	static t_uint	start;
	static t_uint	exit;
	static t_uint	collect;
	char			tile;
	t_coord			crd;

	crd.y = 0;
	while (crd.y < map.height)
	{
		crd.x = 0;
		while (crd.x < map.width)
		{
			tile = ref_tile(map.map, crd);
			start += (tile == PLYR);
			exit += (tile == EXIT);
			collect += (tile == CLEC);
			crd.x++;
		}
		crd.y++;
	}
	if (!(start == 1 && exit == 1 && collect > 0))
	{
		write_error("SOME MISCONFIGURATION WAS DETECTED ON THE MAP");
		exit_with_error(NULL);
	}
}

static void	check_enemy(t_map map)
{
	static t_uint	enemy;
	char			tile;
	t_coord			crd;

	crd.y = 0;
	while (crd.y < map.height)
	{
		crd.x = 0;
		while (crd.x < map.width)
		{
			tile = ref_tile(map.map, crd);
			enemy += (tile == ENMY);
			crd.x++;
		}
		crd.y++;
	}
	if (!(enemy < 2))
	{
		write_error("ONLY ONE ENEMY AVAILABLE");
		exit_with_error(NULL);
	}
}

static void	check_surround_with_wall(t_map map)
{
	t_uint	y;

	y = 0;
	while (y < map.height)
	{
		if (y == 0 || y == map.height - 1)
			check_wall(map.map[y], map.width, FALSE);
		else
			check_wall(map.map[y], map.width, TRUE);
		y++;
	}
}

static void	check_wall(char *line, t_uint width, t_bool is_middle)
{
	if (is_middle)
	{
		if (line[0] != WALL || line[width - 1] != WALL)
		{
			write_error("MAP IS NOT SURROUNDED WITH WALL");
			exit_with_error(NULL);
		}
	}
	else
	{
		while (*line && *line != '\n')
		{
			if (*line != WALL)
			{
				write_error("MAP IS NOT SURROUNDED WITH WALL");
				exit_with_error(NULL);
			}
			line++;
		}
	}
}
