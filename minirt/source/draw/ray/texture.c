/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:35:13 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/10 12:35:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_color	solid(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p);
static t_color	checker(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p);
// static t_color	bumpmap(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p);

t_txtr	texture(t_name name, t_color c1, t_color c2, t_scl inv_scale)
{
	t_txtr	txtr;
	
	if (name == TX_SOLID)
		txtr.value = &solid;
	else if (name == TX_CHKER)
		txtr.value = &checker;
	// else if (name == TX_BUMP)
	// 	txtr.value = &bumpmap;
	txtr.c1 = c1;
	txtr.c2 = c2;
	txtr.inv_scale = 1.0 / inv_scale;
	
	return txtr;
}

static t_color	solid(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p)
{
	(void)txtr;
	(void)u;
	(void)v;
	(void)p;
	
	return (txtr->c1);
}

static t_color	checker(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p)
{
	// (void)p;
	
	// u = clamp(u, interval_set(0, 1));
	// v = 1.0 - clamp(v, interval_set(0, 1));

	// if ((int)(u * txtr->inv_scale + v * txtr->inv_scale) % 2 == 0)
	// 	return (txtr->c1);
	// else
	// 	return (txtr->c2);

	(void)u;
	(void)v;
	
	int	x = (int)floor(txtr->inv_scale * p->x);
	int	y = (int)floor(txtr->inv_scale * p->y);
	int	z = (int)floor(txtr->inv_scale * p->z);

	t_bool	even = ((x + y + z) % 2 == 0);
	if (even)
		return (txtr->c1);
	else
		return (txtr->c2);
}

// static t_color	bumpmap(const t_txtr *txtr, t_scl u, t_scl v, const t_point *p)
// {
// }
