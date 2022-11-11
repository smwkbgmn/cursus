/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:00:16 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 11:07:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		get_info1(t_map *map, char *buf);
int		get_info2(t_map *map, char *buf);
void	get_rest(t_map *map, char *buf, int file_size, int idx);
int		get_line_length(char *buf);

void	get_map(t_map *map, int fd)
{
	char	buf[11000];
	int		file_size;
	int		info1;
	int		info2;

	info1 = 0;
	info2 = 0;
	while (1)
	{
		file_size = read(fd, buf, 11000);
		if (info1 == 0)
		{
			info1 = get_info1(map, buf) + 1;
			info2 = get_info2(map, buf + info1) + 1;
			get_rest(map, buf + info1 + info2, file_size - info1 - info2, 0);
		}
		else
			get_rest(map, buf, file_size, 0);
		if (file_size != 11000)
			break ;
	}
}

int	get_info1(t_map *map, char *buf)
{
	int	len;

	len = get_line_length(buf);
	if (len < 4)
	{
		map->valid = 0;
		return (len);
	}
	map->empty = buf[len - 3];
	map->obstc = buf[len - 2];
	map->full = buf[len - 1];
	buf[len - 3] = '\0';
	map->row = ft_atoi(buf);
	map->valid = valid_info1(map);
	return (len);
}

int	get_info2(t_map *map, char *buf)
{
	int		len;
	int		idx;

	len = get_line_length(buf);
	if (len <= 0)
		map->valid = 0;
	map->col = len;
	map->map = default_map(map->row, map->col);
	if (map->map == 0)
	{
		map->valid = 0;
		return (len);
	}
	idx = -1;
	while (++idx < len + 1)
	{
		if ((idx != len && buf[idx] == map->obstc) \
				|| (idx == len && buf[idx] == '\n'))
			map->map[0][idx] = 0;
		else if (idx != len && buf[idx] == map->empty)
			map->map[0][idx] = 1;
		else
			map->map[0][idx] = -2;
	}
	return (len);
}

void	get_rest(t_map *map, char *buf, int file_size, int idx)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map->row)
	{
		c = -1;
		while (++c < map->col + 1)
		{
			if (map->map[r][c] == -1)
			{
				if (++idx > file_size)
					return ;
				else if ((c == map->col && buf[idx - 1] == '\n') || \
						(c != map->col && buf[idx - 1] == map->obstc))
					map->map[r][c] = 0;
				else if (c != map->col && buf[idx - 1] == map->empty)
					map->map[r][c] = 1;
				else
					map->map[r][c] = -2;
			}
		}
	}
	if (idx != file_size)
		map->valid = 0;
}

int	get_line_length(char *buf)
{
	int	len;

	len = 0;
	while (*buf != '\n')
	{
		len++;
		buf++;
	}
	return (len);
}
