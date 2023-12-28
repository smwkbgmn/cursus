/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 10:53:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	color(t_scl x, t_scl y, t_scl z);

t_ray	ray(t_crd org, t_vec direc)
{
	t_ray	ray;

	ray.org = org;
	ray.direc = direc;
	return (ray);
}

t_crd	ray_at(t_ray *ray, t_scl t)
{
	return (vad(ray->org, vmt(ray->direc, t)));
}

t_color	ray_color(t_ray *ray)
{
	t_uvec	unit_direc;
	t_scl	scale;

	unit_direc = vunit(ray->direc);
	scale = 0.5 * (unit_direc.y + 1.0);
	return (vad(vmt(color(1.0, 1.0, 1.0), 1.0 - scale), vmt(color(0.5, 0.7, 1.0), scale)));
}

static t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}