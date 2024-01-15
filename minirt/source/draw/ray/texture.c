/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:35:13 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/15 17:54:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_color	solid(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p);
static t_color	checker(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p);

t_txtr	texture(t_name name, t_color first, t_color second, t_scl scale)
{
	t_txtr	txtr;
	
	if (name == TX_SOLID)
		txtr.value = &solid;
	else if (name == TX_CHKER)
		txtr.value = &checker;
	txtr.albedo = first;
	txtr.chker_secondcolor = second;
	txtr.chker_scale = 1.0 / scale;
	
	return txtr;
}

static t_color	solid(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p)
{
	(void)txtr;
	(void)u;
	(void)v;
	(void)p;
	
	return (txtr->albedo);
}

static t_color	checker(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p)
{
	(void)u;
	(void)v;
	
	int	x = (int)floor(txtr->chker_scale * p->x);
	int	y = (int)floor(txtr->chker_scale * p->y);
	int	z = (int)floor(txtr->chker_scale * p->z);

	t_bool	even = ((x + y + z) % 2 == 0);
	if (even)
		return (txtr->albedo);
	else
		return (txtr->chker_secondcolor);
}
