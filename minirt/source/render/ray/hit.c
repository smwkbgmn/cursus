/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		set_sphere_uv(t_uvec p, t_hit *rec);
static void		set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r);
static void		set_face_normal(t_hit *rec, const t_ray *r,
					t_vec outward_normal);

t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_hit		rec_tmp;
	t_bool		hit_anything = FALSE;
	t_scl		closest_so_far = t.max;

	while (objs)
	{
		if (((t_obj *)objs->content)->hit(objs->content,
				r, interval(t.min, closest_so_far), &rec_tmp))
		{
			hit_anything = TRUE;
			closest_so_far = rec_tmp.t;
			*rec = rec_tmp;
		}
		objs = objs->next;
	}
	return (hit_anything);
}

t_bool	hit_plane(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_scl	denom = dot(obj->val.sqr.normal, r->dir);

	// No hit if the ray is parallel to the plane
	if (fabs(denom) < 1e-8)
		return FALSE;

	// ORIGINAL
	t_scl	d = dot(obj->val.sqr.point, obj->val.sqr.normal);
	t_scl	t = (d - dot(obj->val.sqr.normal, r->org)) / denom;

	// GPT
	// t_vec	tmp = mtv(sb(obj->val.sqr.point, r->origin), obj->val.sqr.normal);
	// t_scl	t = (tmp.x + tmp.y + tmp.z) / denom;
	
	if (!contains(t, ray_t))
		return FALSE;

	// ORIGINAL
	t_point	intersection = ray_at(r, t);
	
	rec->t = t;
	rec->point = intersection;
	rec->txtr = &obj->txtr;
	set_face_normal(rec, r, obj->val.sqr.normal);

	return (TRUE);
}

t_bool	hit_sphere(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_eqa	eqa;

	t_scl	sqrtd;
	t_scl	root;
	t_vec	outward_normal;
	
	set_equation(&eqa, obj, r);
	if (eqa.dscr < 0)
		return (FALSE);
	
	sqrtd = sqrt(eqa.dscr);
	// Find the nearest root that lines in the acceptable range
	root = (-eqa.b_half - sqrtd) / eqa.a;
	if (!surrounds(root, t))
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (!surrounds(root, t))
			return (FALSE);
	}

	rec->t = root;
	rec->point = ray_at(r, rec->t);
	rec->txtr = &obj->txtr;

	outward_normal = dv(sb(rec->point, obj->val.cir.center), obj->val.cir.radius);
	set_face_normal(rec, r, outward_normal);

	set_sphere_uv(outward_normal, rec); // For texture mapping

	return (TRUE);
}

static void	set_sphere_uv(t_uvec p, t_hit *rec)
{
	/*
		p: A given point on the sphere of radius one, centered at the origin
		u: Returned value [0, 1] of angle around the Y axis from x = -1
		v: Returned value [0, 1] of angle from Y = -1 to y = +1
			<1 0 0> tyelds <0.50 0.50>	<-1  0  0> yields <0.00 0.50>
			<0 1 0> tyelds <0.50 1.00>	< 0 -1  0> yields <0.50 0.00>
			<0 0 1> tyelds <0.25 0.50>	< 0  0 -1> yields <0.75 0.50>
	*/
	t_scl	theta = acos(-p.y);
	t_scl	phi = atan2(-p.z, p.x) + M_PI;

	rec->map.x = phi / (2 * M_PI);
	rec->map.y = theta / M_PI;
}

static void	set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r)
{
	eqa->oc = sb(r->org, obj->val.cir.center);
	eqa->a = square(r->dir);
	eqa->b_half = dot(eqa->oc, r->dir);
	eqa->c = square(eqa->oc) - pow(obj->val.cir.radius, 2);
	
	eqa->dscr = pow(eqa->b_half, 2) - (eqa->a * eqa->c);
}

// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
// {

// }

static void	set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal)
{
	// The parameter 'outward_normal' is assumed to have unit len
	rec->face = dot(r->dir, outward_normal) < 0;
	if (rec->face)
		rec->normal = outward_normal;
	else
		rec->normal = mt(outward_normal, -1);
}
