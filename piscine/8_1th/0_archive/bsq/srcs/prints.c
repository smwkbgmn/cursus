/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:08:48 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 11:10:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map, t_answ *answ)
{
	int	r;
	int	c;

	if (map->valid == 0)
		print_map_error();
	else
	{
		r = -1;
		while (++r < map->row)
		{
			c = -1;
			while (++c < map->col)
			{
				if ((r > answ->row - answ->largest && r <= answ->row) && \
					(c > answ->col - answ->largest && c <= answ->col))
					ft_putchar(map->full);
				else if (map->map[r][c] == 0)
					ft_putchar(map->obstc);
				else
					ft_putchar(map->empty);
			}
			ft_putchar('\n');
		}
	}
}

void	print_map_error(void)
{
	ft_putstr("map error\n");
}

void	print_malloc_error(void)
{
	ft_putstr("memory allocation failed\n");
}
