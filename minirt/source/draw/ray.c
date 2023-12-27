/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:04:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_color	color(t_scl x, t_scl y, t_scl z);

// The function says that it takes directions and
// do getting unit of this what the fuck are you doiing?
t_ray	ray(t_crd org, t_vec wtf)
{
	t_ray	ray;

	ray.org = org;
	ray.unit = vunit(wtf);
	return (ray);
}

t_crd	ray_at(t_ray *ray, t_scl val)
{
	return (vadd(ray->org, vmulti(ray->unit, val)));
}

t_ray	ray_primary(t_camera *cam, t_scl u, t_scl v)
{
	t_ray	ray;

	ray.org = cam->crd;
	ray.unit = vunit(vsub(vadd(vadd(cam->left_bottom, vmulti(cam->horizon, u)), vmulti(cam->vertical, v)), cam->crd));
	return (ray);
}

t_color	ray_color(t_ray *ray)
{
	t_scl	val;

	val = 0.5 * (ray->unit.y + 1.0);
	return (vadd(vmulti(color(1, 1, 1), 1.0 - val), vmulti(color(0.5, 0.7, 1.0), val)));
}

static t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}