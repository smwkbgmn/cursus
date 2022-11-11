/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:59:44 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 10:59:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		increase(int **map, int r, int c);
int		get_smlst(int val_diago, int val_up, int val_left);
void	renew_answ(t_answ *answ, int r, int c, int largest);

t_answ	*get_answ(t_map *map)
{
	t_answ	*answ;
	int		r;
	int		c;

	answ = (t_answ *)malloc(sizeof(t_answ));
	if (answ == 0)
		return (0);
	default_answ(answ);
	r = -1;
	while (++r < map->row && map->valid == 1)
	{
		c = -1;
		while (++c < map->col)
		{
			if (map->map[r][c] != 0)
			{
				if (r != 0 && c != 0)
					map->map[r][c] = increase(map->map, r, c);
				if (map->map[r][c] > answ->largest)
					renew_answ(answ, r, c, map->map[r][c]);
			}
		}
	}
	return (answ);
}

int	increase(int **map, int r, int c)
{
	int	lowest;

	lowest = get_smlst(map[r - 1][c - 1], map[r - 1][c], map[r][c - 1]);
	lowest++;
	return (lowest);
}

int	get_smlst(int val_diago, int val_up, int val_left)
{
	int	smlst;

	smlst = val_diago;
	if (smlst > val_up)
		smlst = val_up;
	if (smlst > val_left)
		smlst = val_left;
	return (smlst);
}

void	renew_answ(t_answ *answ, int r, int c, int largest)
{
	answ->row = r;
	answ->col = c;
	answ->largest = largest;
}
