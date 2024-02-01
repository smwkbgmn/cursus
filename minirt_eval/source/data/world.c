/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:52:26 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:19:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_circle	circle(t_point center, t_scl diameter)
{
	t_circle	cir;

	cir.center = center;
	cir.radius = valid_size(diameter) / 2;
	return (cir);
}

t_obj	*sphere(t_circle cir, t_txtr txtr)
{
	t_obj	*obj;

	obj = try(ft_calloc(1, sizeof(t_obj)));
	obj->name = SPHERE;
	obj->val.cir.center = cir.center;
	obj->val.cir.radius = cir.radius;
	obj->hit = &hit_sphere;
	obj->txtr = txtr;
	return (obj);
}

t_obj	*plane(t_point point_on_plane, t_uvec normal, t_txtr txtr)
{
	t_obj	*obj;

	obj = try(ft_calloc(1, sizeof(t_obj)));
	obj->name = PLANE;
	obj->val.sqr.point = point_on_plane;
	obj->val.sqr.normal = valid_normal(normal);
	obj->hit = &hit_plane;
	obj->txtr = txtr;
	return (obj);
}

t_obj	*cylinder(t_circle cir, t_scl height, t_uvec axis, t_txtr txtr)
{
	t_obj	*obj;

	obj = try(ft_calloc(1, sizeof(t_obj)));
	obj->name = CYLNDR;
	obj->val.cir.center = cir.center;
	obj->val.cir.radius = cir.radius;
	obj->val.cyl.height = valid_size(height);
	obj->val.cyl.axis = valid_normal(axis);
	obj->val.cyl.base = sb(cir.center, dv(mt(axis, height / 2), length(axis)));
	obj->val.cyl.top = ad(cir.center, dv(mt(axis, height / 2), length(axis)));
	obj->val.cyl.axis = unit(sb(obj->val.cyl.top, obj->val.cyl.base));
	obj->hit = &hit_cylinder;
	obj->txtr = txtr;
	return (obj);
}

t_light	*light(t_point position, t_color rgb, t_scl bright)
{
	t_light	*light;

	light = try(ft_calloc(1, sizeof(t_light)));
	light->point = position;
	light->albedo = albedo_rgb(rgb, bright);
	return (light);
}
