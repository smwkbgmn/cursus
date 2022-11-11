/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:10:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/15 11:11:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**default_map(int r, int c)
{
	int	**map;
	int	rr;
	int	cc;

	if (r <= 0 || c <= 0)
		return (0);
	map = (int **) malloc(sizeof(int *) * r);
	if (map == 0)
		return (0);
	rr = 0;
	while (rr < r)
	{
		map[rr] = (int *)malloc(sizeof(int) * (c + 1));
		if (map[rr] == 0)
		{
			free(map);
			map = 0;
			return (0);
		}
		cc = 0;
		while (cc < c + 1)
			map[rr][cc++] = -1;
		rr++;
	}
	return (map);
}

void	default_answ(t_answ *answ)
{
	answ->row = 0;
	answ->col = 0;
	answ->largest = 0;
}
