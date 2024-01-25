/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:52:26 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 08:14:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_light	*light(t_point position, t_color rgb, t_scl bright)
{
	t_light	*light = try(ft_calloc(1, sizeof(t_light)));

	light->pos = position;
	light->albedo = albedo_rgb(rgb, bright);
	return (light);
}

t_obj	*sphere(t_circle cir, t_txtr txtr)
{
	t_obj	*obj = try(ft_calloc(1, sizeof(t_obj)));

	obj->name = SPHERE;
	obj->val.cir.center = cir.center;
	obj->val.cir.radius = cir.radius;
	obj->hit = &hit_sphere;
	obj->txtr = txtr;
	return (obj);
}

t_obj	*plane(t_point point_on_plane, t_uvec normal, t_txtr txtr)
{
	t_obj	*obj = try(ft_calloc(1, sizeof(t_obj)));
	
	obj->name = PLANE;
	obj->val.sqr.point = point_on_plane;
	obj->val.sqr.normal = normal;
	obj->hit = &hit_plane;
	obj->txtr = txtr;
	return (obj);
}

t_obj	*cylinder(t_circle cir, t_scl height, t_uvec axis, t_txtr txtr)
{
	t_obj	*obj = try(ft_calloc(1, sizeof(t_obj)));

	obj->name = CYLNDR;
	obj->val.cir.center = cir.center;
	obj->val.cir.radius = cir.radius;
	obj->val.height = height;
	obj->val.axis = axis;
	obj->txtr = txtr;
	return (obj);
}

t_circle	circle(t_point center, t_scl diameter)
{
	t_circle	cir;

	cir.center = center;
	cir.radius = diameter / 2;
	return (cir);
}

t_color	albedo_rgb(t_color rgb, t_scl bright)
{
	return (mt(color(rgb.x / 255, rgb.y / 255, rgb.z / 255), bright));
}
