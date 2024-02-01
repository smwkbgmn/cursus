/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:10:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray(t_point org, t_uvec dir)
{
	t_ray	r;

	r.org = org;
	r.dir = dir;
	return (r);
}

t_point	ray_at(const t_ray *r, t_scl t)
{
	return (ad(r->org, mt(r->dir, t)));
}

t_color	ray_color(const t_ray *r, const t_world *world)
{
	t_hit	rec;

	ft_memset(&rec, NONE, sizeof(t_hit));
	if (hit(world->objs, r, interval(0.001, INFINITY), &rec))
		return (color_at(&rec, world, mt(r->dir, -1)));
	return (color(0, 0, 0));
}
