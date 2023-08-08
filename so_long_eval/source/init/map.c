/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/08 15:43:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "so_long.h"

static void	read_map(int fd, t_map *map, t_uint x, t_uint y);
static void	check_width_height(t_map *map, t_uint x, t_uint y);
static void	check_letters(char *line);
static void	check_valid_size(t_uint x, t_uint y);

void	init_map(t_map *map, char *filename)
{
	int		fd_map;
	char	*extension;

	fd_map = open_fd(filename, O_RDONLY);
	extension = ft_strrchr(filename, '.');
	if (!extension
		|| ft_strlen(extension) < 4
		|| ft_strncmp(extension, ".ber", ft_strlen(extension)) != 0)
	{
		write_error("CAN NOT READ FILE");
		exit_with_error(NULL);
	}
	read_map(fd_map, map, 0, 0);
	close_fd(fd_map);
}

static void	read_map(int fd, t_map *map, t_uint x, t_uint y)
{
	char			*line;

	line = get_next_line(fd);
	if (line)
	{
		x = ft_strlen(line) - (ft_strchr(line, '\n') != NULL);
		check_width_height(map, x, ++y);
		check_letters(line);
		read_map(fd, map, x, y);
	}
	else
	{
		check_valid_size(x, y);
		map->map = catcher(ft_calloc(map->height, sizeof(char *)));
	}
	if (map->map)
		map->map[y - 1] = line;
	else
		ft_free(line);
}

static void	check_width_height(t_map *map, t_uint x, t_uint y)
{
	if (x == map->width || y == 1)
	{
		map->width = x;
		map->height = y;
	}
	else
	{
		write_error("NOT RECTANGULAR");
		exit_with_error(NULL);
	}
}

static void	check_letters(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != EMTY && *line != WALL
			&& *line != CLEC && *line != EXIT
			&& *line != PLYR && *line != ENMY)
		{
			write_error("NOT VALID INPUT");
			exit_with_error(NULL);
		}
		line++;
	}
}

static void	check_valid_size(t_uint x, t_uint y)
{
	if (!((x > 2 && y > 4)
			|| (x > 3 && y > 3)
			|| (x > 4 && y > 2)))
	{
		if (y == 0)
			write_error("NO MAP DATA");
		else
			write_error("NOT VALID SIZE");
		exit_with_error(NULL);
	}
}
