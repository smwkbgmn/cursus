/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:35:13 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 08:33:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"

static t_color	solid(const t_hit *rec);
static t_color	checker(const t_hit *rec);

t_txtr	texture(t_name name, t_color first, t_color second, t_scl scale)
{
	t_txtr	txtr;
	
	if (name == TX_SOLID)
		txtr.value = &solid;
	else if (name == TX_CHKER)
		txtr.value = &checker;
	txtr.albedo1 = albedo_rgb(first, 1);
	txtr.albedo2 = albedo_rgb(second, 1);
	txtr.scale = 1.0 / scale;
	
	return txtr;
}

static t_color	solid(const t_hit *rec)
{
	return (rec->txtr->albedo1);
}

static t_color	checker(const t_hit *rec)
{
	int	x = (int)floor(rec->txtr->scale * rec->point.x);
	int	y = (int)floor(rec->txtr->scale * rec->point.y);
	int	z = (int)floor(rec->txtr->scale * rec->point.z);

	t_bool	even = ((x + y + z) % 2 == 0);
	if (even)
		return (rec->txtr->albedo1);
	else
		return (rec->txtr->albedo2);
}
