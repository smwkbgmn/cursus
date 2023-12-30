/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/30 14:18:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	color(t_scl x, t_scl y, t_scl z);

t_ray	ray(t_crd pos, t_vec direc)
{
	t_ray	r;

	r.pos = pos;
	r.direc = direc;
	return (r);
}

t_crd	ray_at(t_ray *r, t_scl t)
{
	return (ad(r->pos, mt(r->direc, t)));
}

t_color	ray_color(t_ray *r)
{
	t_uvec	unit_direc;
	t_scl	scale;

	if (hit_sphere(pos(0, 0, -1), 0.5, *r))
		return (color(1, 0, 0));

	unit_direc = unit(r->direc);
	scale = 0.5 * (unit_direc.y + 1.0);
	return (ad(mt(color(1.0, 1.0, 1.0), 1.0 - scale), mt(color(0.5, 0.7, 1.0), scale)));
}

static t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}