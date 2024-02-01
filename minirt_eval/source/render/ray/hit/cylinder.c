/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:12:33 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:13:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	hit_endcap(t_obj *obj, const t_ray *r,
					t_intvl ray_t, t_hit *rec);
static t_bool	hit_seam(t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec);
static void		set_equation(t_eqa *eqa, t_obj *obj, const t_ray *r);
static t_bool	set_normal(t_obj *obj, t_hit *rec);

t_bool	hit_cylinder(t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_bool	does_hit;
	t_point	middle;

	does_hit = FALSE;
	middle = obj->val.cir.center;
	obj->val.cir.center = obj->val.cyl.top;
	if (hit_endcap(obj, r, ray_t, rec))
	{
		ray_t.max = rec->t;
		rec->normal = unit(obj->val.cyl.axis);
		does_hit = TRUE;
	}
	obj->val.cir.center = obj->val.cyl.base;
	if (hit_endcap(obj, r, ray_t, rec))
	{
		ray_t.max = rec->t;
		rec->normal = mt(unit(obj->val.cyl.axis), -1);
		does_hit = TRUE;
	}
	obj->val.cir.center = middle;
	if (hit_seam(obj, r, ray_t, rec))
		does_hit = TRUE;
	rec->txtr = &obj->txtr;
	return (does_hit);
}

static t_bool	hit_endcap(t_obj *obj, const t_ray *r,
					t_intvl ray_t, t_hit *rec)
{
	t_vec	center;
	t_uvec	axis;
	t_scl	pc_len;
	t_scl	t;

	center = obj->val.cir.center;
	axis = obj->val.cyl.axis;
	t = dot(sb(center, r->org), axis) / dot(r->dir, axis);
	pc_len = length(sb(center, ray_at(r, t)));
	if (obj->val.cir.radius < fabs(pc_len) || !contains(t, ray_t))
		return (FALSE);
	rec->t = t;
	rec->point = ray_at(r, t);
	return (TRUE);
}

static t_bool	hit_seam(t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_eqa	eqa;
	t_scl	sqrtd;
	t_scl	root;

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
	rec->point = ray_at(r, root);
	if (!set_normal(obj, rec))
		return (FALSE);
	set_face_normal(rec, r, rec->normal);
	rec->txtr = &obj->txtr;
	return (TRUE);
}

static void	set_equation(t_eqa *eqa, t_obj *obj, const t_ray *r)
{
	t_vec	cl;
	t_scl	vh;
	t_scl	wh;

	cl = sb(r->org, obj->val.cir.center);
	vh = dot(r->dir, obj->val.cyl.axis);
	wh = dot(cl, obj->val.cyl.axis);
	eqa->a = square(r->dir) - vh * vh;
	eqa->b_half = dot(r->dir, cl) - vh * wh;
	eqa->c = square(cl) - wh * wh - pow(obj->val.cir.radius, 2);
	eqa->dscr = pow(eqa->b_half, 2) - eqa->a * eqa->c;
}

static t_bool	set_normal(t_obj *obj, t_hit *rec)
{
	t_vec	cp;
	t_vec	cq;
	t_scl	hit_h;

	cp = sb(rec->point, obj->val.cir.center);
	hit_h = sqrt(square(cp) - pow(obj->val.cir.radius, 2));
	if (obj->val.cyl.height / 2 < hit_h)
		return (FALSE);
	if (dot(obj->val.cyl.axis, unit(cp)) >= 0)
		cq = ad(obj->val.cir.center, mt(obj->val.cyl.axis, hit_h));
	else
		cq = ad(obj->val.cir.center, mt(obj->val.cyl.axis, -hit_h));
	rec->normal = unit(sb(rec->point, cq));
	return (TRUE);
}
