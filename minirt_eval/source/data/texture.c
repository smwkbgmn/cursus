/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:35:13 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 16:42:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_color	solid(const t_hit *rec);
static t_color	checker(const t_hit *rec);

t_txtr	texture(char **argv)
{
	t_txtr	txtr;

	ft_memset(&txtr, NONE, sizeof(t_txtr));
	txtr.albedo1 = albedo_rgb(get_color(argv[0]), 1);
	if (argv[1])
	{
		txtr.value = &checker;
		txtr.albedo2 = albedo_rgb(get_color(argv[1]), 1);
		txtr.scale = 1.0 / get_scl(argv[2], interval(0.5, 5));
	}
	else
		txtr.value = &solid;
	return (txtr);
}

static t_color	solid(const t_hit *rec)
{
	return (rec->txtr->albedo1);
}

static t_color	checker(const t_hit *rec)
{
	t_bool	even;
	int		x;
	int		y;
	int		z;

	x = (int)floor(rec->txtr->scale * rec->point.x);
	y = (int)floor(rec->txtr->scale * rec->point.y);
	z = (int)floor(rec->txtr->scale * rec->point.z);
	even = ((x + y + z) % 2 == 0);
	if (even)
		return (rec->txtr->albedo1);
	else
		return (rec->txtr->albedo2);
}
