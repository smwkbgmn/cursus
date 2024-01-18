/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:52:26 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/17 08:35:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_light	*light(t_point position, t_color rgb, t_scl bright)
{
	t_light	*light = ft_calloc(1, sizeof(t_light));

	light->pos = position;
	light->albedo = albedo_rgb(rgb, bright);
	return (light);
}

t_obj	*sphere(t_point center, t_scl radius, t_mtral mtral)
{
	t_obj	*obj = ft_calloc(1, sizeof(t_obj));

	obj->name = SPHERE;
	obj->val.cir.center = center;
	obj->val.cir.radius = radius;
	obj->hit = &hit_sphere;
	obj->mtral = mtral;
	return (obj);
}

// t_obj	*plane(t_point point, t_uvec normal, const t_mtral *mtral)
t_obj	*plane(t_point q, t_vec u, t_vec v, t_mtral mtral)
{
	t_obj	*obj = ft_calloc(1, sizeof(t_obj));

	obj->name = PLANE;

	obj->val.sqr.point = q;
	obj->val.sqr.u = u;
	obj->val.sqr.v = v;
	
	t_vec	n = cross(u, v);
	obj->val.sqr.normal = unit(n);
	obj->val.sqr.d = dot(obj->val.sqr.normal, q);
	obj->val.sqr.w = dv(n, dot(n, n));

	obj->hit = &hit_plane;
	obj->mtral = mtral;
	return (obj);
}

t_color	albedo_rgb(t_color rgb, t_scl ratio)
{
	return (mt(color(rgb.x / 255.999, rgb.y / 255.999, rgb.z / 255.999), ratio));
}
