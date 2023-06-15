/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 21:13:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "so_long.h"

t_bool	check_width_height(char *line, t_map *map, t_uint *x, t_uint *y);
t_bool	check_letters(char *line);
void	read_map(int fd, t_map *map, t_uint x, t_uint y);
t_bool	is_valid_size(t_uint x, t_uint y);

t_map	init_map(char *filename)
{
	t_map	map;

	map.map = NULL;
	read_map(open(filename, O_RDONLY), &map, 0, 0);
	return (map);
}

void	read_map(int fd, t_map *map, t_uint x, t_uint y)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		if (check_width_height(line, map, &x, &y) && check_letters(line))
			read_map(fd, map, x, y);
	}
	else
	{
		if (is_valid_size(x, y))
			map->map = ft_calloc(map->height, sizeof(char *));
		else if (y > 0)
			write_error("NOT VALID SIZE");
	}
	if (map->map)
		map->map[y - 1] = line;
	else
		ft_free(line);
}

t_bool	check_width_height(char *line, t_map *map, t_uint *x, t_uint *y)
{
	*x = ft_strlen(line) - (ft_strchr(line, '\n') != NULL);
	(*y)++;
	if (*x == map->width || *y == 1)
	{
		map->width = *x;
		map->height = *y;
		return (TRUE);
	}
	else
	{
		write_error("NOT RECTANGULAR");
		return (FALSE);
	}
}

t_bool	check_letters(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != EMTY && *line != WALL
			&& *line != CLEC && *line != EXIT
			&& *line != PLYR && *line != ENMY)
		{
			write_error("NOT VALID CHARACTER");
			return (FALSE);
		}
		line++;
	}
	return (TRUE);
}

t_bool	is_valid_size(t_uint x, t_uint y)
{
	return ((x > 2 && y > 4)
		|| (x > 3 && y > 3)
		|| (x > 4 && y > 2));
}
