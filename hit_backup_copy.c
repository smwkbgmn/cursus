/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/31 19:43:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "data.h"

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

t_bool	hit_sphere(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
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
	if (!surrounds(root, ray_t))
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (!surrounds(root, ray_t))
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

static void	set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r)
{
	eqa->oc = sb(r->org, obj->val.cir.center);
	eqa->a = square(r->dir);
	eqa->b_half = dot(eqa->oc, r->dir);
	eqa->c = square(eqa->oc) - pow(obj->val.cir.radius, 2);
	
	eqa->dscr = pow(eqa->b_half, 2) - (eqa->a * eqa->c);
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

#include <stdio.h>

t_bool	hit_endcap(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec,
	t_scl h_hlaf_signed, t_uvec axis);
t_bool	hit_seam(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec, t_uvec axis);

t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	// t_scl	height = obj->val.height;
	t_scl	h_half = obj->val.height / 2;
	// t_scl	radius = obj->val.cir.radius;
	t_point	center = obj->val.cir.center;
	t_uvec	dir = obj->val.axis;

	t_scl	len_dir = length(dir);
	t_point	base = sb(center, dv(mt(dir, h_half), len_dir));
	t_point	top = ad(center, dv(mt(dir, h_half), len_dir));

	
	t_uvec	axis = unit(sb(top, base));
	// t_uvec	axis = dir;

	t_bool	does_hit = FALSE;

	///////////////////////////////////////////////////////////////

	if (hit_endcap(obj, r, ray_t, rec, h_half, axis))
	{
		ray_t.max = rec->t;
		does_hit = TRUE;
	}
	if (hit_endcap(obj, r, ray_t, rec, -h_half, axis))
	{
		ray_t.max = rec->t;
		does_hit = TRUE;
	}
	if (hit_seam(obj, r, ray_t, rec, axis))
		does_hit = TRUE;
	return (does_hit);
}

t_bool	hit_endcap(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec,
	t_scl h_hlaf_signed, t_uvec axis)
{
	t_scl	pc_len;
	t_scl	t;
	t_vec	center;
	t_scl	axis_len = length(obj->val.axis); 

	center = ad(obj->val.cir.center, dv(mt(obj->val.axis, h_hlaf_signed), axis_len));
	t = dot(sb(center, r->org), axis) / dot(r->dir, axis);
	pc_len = length(sb(center, ray_at(r, t)));
	if (obj->val.cir.radius < fabs(pc_len) || !contains(t, ray_t))
		return (FALSE);
	if (h_hlaf_signed > 0)
		rec->normal = unit(axis);
	else
		rec->normal = mt(unit(axis), -1);
	rec->t = t;
	rec->point = ray_at(r, t);
	rec->txtr = &obj->txtr;
	
	set_face_normal(rec, r, rec->normal);
	return (TRUE);
}

t_bool	hit_seam(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec, t_uvec axis)
{
	(void)ray_t;

	t_eqa	eqa;
	t_vec	cl = sb(r->org, obj->val.cir.center);
	t_scl	vh = dot(r->dir, axis);
	t_scl	wh = dot(cl, axis);

	eqa.a = square(r->dir) - vh * vh;
	eqa.b_half = dot(r->dir, cl) - vh * wh;
	eqa.c = square(cl) - wh * wh - pow(obj->val.cir.radius, 2);
	eqa.dscr = pow(eqa.b_half, 2) - eqa.a * eqa.c;

	if (eqa.dscr < 0)
		return (FALSE);

	t_scl	sqrtd;
	t_scl	root;

	sqrtd = sqrt(eqa.dscr);
	// Find the nearest root that lines in the acceptable range
	root = (-eqa.b_half - sqrtd) / eqa.a;
	if (!surrounds(root, ray_t))
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (!surrounds(root, ray_t))
			return (FALSE);
	}

	t_vec	intersection = ray_at(r, root);
	t_vec	cp = sb(intersection, obj->val.cir.center);
	// t_scl	hit_h = length(cp) - pow(obj->val.cir.radius, 2);
	t_scl	hit_h = sqrt(square(cp) - pow(obj->val.cir.radius, 2));

	if (obj->val.height / 2 < hit_h)
		return (FALSE);
		
	t_vec	cq;
	if (dot(axis, unit(cp)) >= 0)
		cq = ad(obj->val.cir.center, mt(axis, hit_h));
	else
		cq = ad(obj->val.cir.center, mt(axis, -hit_h));

	// t_vec	outward_normal = unit(sb(intersection, cq));
	// set_face_normal(rec, r, outward_normal);
	
	rec->normal = unit(sb(intersection, cq));
	
	rec->t = root;
	rec->point = intersection;
	rec->txtr = &obj->txtr;

	return (TRUE);
}

// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
// {
// 	(void)ray_t;
	
// 	t_scl	height = obj->val.height;
// 	t_scl	h_half = obj->val.height / 2;
// 	t_scl	radius = obj->val.cir.radius;
// 	t_point	center = obj->val.cir.center;
// 	t_uvec	dir = obj->val.axis;
	
// 	t_scl	len_dir = length(dir);

// 	center = sb(center, r->org);
// 	t_point	base = sb(center, dv(mt(dir, h_half), len_dir));
// 	t_point	top = ad(center, dv(mt(dir, h_half), len_dir));

// 	t_uvec	axis = unit(sb(top, base));

// 	t_uvec	raydir_axis = cross(r->dir, axis);
// 	t_scl	sqrt1 = dot(raydir_axis, mt(raydir_axis, radius * radius));
// 	t_scl	sqrt2 = dot(axis, axis) * pow(dot(base, raydir_axis), 2);
// 	t_scl	sqrted = sqrt(sqrt1 - sqrt2);
// 	t_scl	front = dot(raydir_axis, cross(base, axis));
// 	t_scl	below = dot(raydir_axis, raydir_axis);

// 	t_scl	d_seam1 = (front + sqrted) / below;
// 	t_scl	d_seam2 = (front - sqrted) / below;
// 	t_scl	t1 = dot(axis, sb(mt(r->dir, d_seam1), base));
// 	t_scl	t2 = dot(axis, sb(mt(r->dir, d_seam2), base));

// 	t_scl	d_seam = fmin(d_seam1, d_seam2);
// 	// t_point	inter_seam = mt(r->dir, d_seam);
// 	t_point	inter_seam = ray_at(r, d_seam);
// 	t_scl	t = dot(axis, sb(inter_seam, base));

// 	t_bool	does_hit = FALSE;

// 	// for end caps
// 	t_scl	d_base = dot(axis, base) / dot(axis, r->dir);
// 	t_scl	d_top = dot(axis, top) / dot(axis, r->dir);

// 	// t_point	inter_base = mt(r->dir, d_base);
// 	// t_point	inter_top = mt(r->dir, d_top);
// 	t_point	inter_base = ray_at(r, d_base);
// 	t_point	inter_top = ray_at(r, d_top);

	

// 	// if (dot(sb(inter_base, base), sb(inter_base, base)) < pow(radius, 2))
// 	if (0 <= t && t < 1e-8)
// 	{
// 		if (!surrounds(d_base, ray_t))
// 			return (FALSE);
			
// 		printf("\tHIT BASE\n");
// 		printf("\t\tray from(%.2f, %.2f, %.2f)\n", r->org.x, r->org.y, r->org.z);
// 		printf("\t\tray dir(%.2f, %.2f, %.2f)\n", r->dir.x, r->dir.y, r->dir.z);

// 		rec->t = d_base;
// 		rec->point = inter_base;
// 		rec->normal = mt(axis, -1);
		
// 		rec->txtr = &obj->txtr;
// 		does_hit = TRUE;
// 	}
	

// 	// if (dot(sb(inter_top, top), sb(inter_top, top)) < pow(radius, 2))
// 	if ((height - 1e-8 < t && t <= height) &&
// 		(!does_hit || d_top < rec->t))
// 	{
// 		if (!surrounds(d_top, ray_t))
// 			return (FALSE);
			
// 		printf("\tHIT TOP\n");
// 		printf("\t\tray from(%.2f, %.2f, %.2f)\n", r->org.x, r->org.y, r->org.z);
// 		printf("\t\tray dir(%.2f, %.2f, %.2f)\n", r->dir.x, r->dir.y, r->dir.z);

// 		rec->t = d_top;
// 		rec->point = inter_top;
// 		rec->normal = axis;

// 		rec->txtr = &obj->txtr;
// 		does_hit = TRUE;
// 	}


// 	if ((0 <= t && t <= height) &&
// 		(!does_hit || d_seam < rec->t))
// 	{
// 		if (!surrounds(d_seam, ray_t))
// 			return (FALSE);
			
// 		printf("\tHIT SEAM\n");
// 		printf("\t\tray from(%.2f, %.2f, %.2f)\n", r->org.x, r->org.y, r->org.z);
// 		printf("\t\tray dir(%.2f, %.2f, %.2f)\n", r->dir.x, r->dir.y, r->dir.z);
// 		printf("\t\td1, t1(%.2f, %.2f) / d2, t2(%.2f, %.2f)\n", d_seam1, t1, d_seam2, t2);
// 		printf("\t\tintersection(%.2f, %.2f, %.2f)\n",
// 			inter_seam.x, inter_seam.y, inter_seam.z);
			
// 		rec->t = d_seam;
// 		rec->point = inter_seam;
// 		// rec->normal = unit(sb(sb(inter_seam, mt(axis, t)), base));
// 		rec->normal = unit(sb(sb(inter_seam, mt(axis, t)), ad(base, r->org)));

// 		rec->txtr = &obj->txtr;
// 		does_hit = TRUE;
// 	}
	
// 	return (does_hit);
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
