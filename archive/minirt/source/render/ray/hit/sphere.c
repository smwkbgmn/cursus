/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:17:33 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:12:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	set_equation(t_eqa *eqa, t_obj *obj, const t_ray *r);
static void	set_sphere_uv(t_uvec p, t_hit *rec);

t_bool	hit_sphere(t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_eqa	eqa;
	t_scl	sqrtd;
	t_scl	root;
	t_vec	outward_normal;

	set_equation(&eqa, obj, r);
	if (eqa.dscr < 0)
		return (FALSE);
	sqrtd = sqrt(eqa.dscr);
	root = (-eqa.b_half - sqrtd) / eqa.a;
	if (!surrounds(root, ray_t))
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (!surrounds(root, ray_t))
			return (FALSE);
	}
	rec->t = root;
	rec->point = ray_at(r, rec->t);
	rec->txtr = &obj->txtr;
	outward_normal = dv(sb(rec->point,
				obj->val.cir.center), obj->val.cir.radius);
	set_face_normal(rec, r, outward_normal);
	set_sphere_uv(outward_normal, rec);
	return (TRUE);
}

static void	set_equation(t_eqa *eqa, t_obj *obj, const t_ray *r)
{
	eqa->oc = sb(r->org, obj->val.cir.center);
	eqa->a = square(r->dir);
	eqa->b_half = dot(eqa->oc, r->dir);
	eqa->c = square(eqa->oc) - pow(obj->val.cir.radius, 2);
	eqa->dscr = pow(eqa->b_half, 2) - (eqa->a * eqa->c);
}

static void	set_sphere_uv(t_uvec p, t_hit *rec)
{
	t_scl	theta;
	t_scl	phi;

	theta = acos(-p.y);
	phi = atan2(-p.z, p.x) + M_PI;
	rec->map.x = phi / (2 * M_PI);
	rec->map.y = theta / M_PI;
}
