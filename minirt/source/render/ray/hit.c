/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/26 13:25:55 by donghyu2         ###   ########.fr       */
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

#include <stdio.h>

t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_scl	height = obj->val.height;
	t_scl	h_half = obj->val.height / 2;
	t_scl	radius = obj->val.cir.radius;
	t_point	center = obj->val.cir.center;
	t_uvec	axis = obj->val.axis;
	
	t_point	base = mtv(ad(obj->val.cir.center, vec(h_half, h_half, h_half)), axis);

	t_scl	sqrt1 = dot(cross(r->dir, axis), mt(cross(r->dir, axis), pow(radius, 2)));
	t_scl	sqrt2 = dot(axis, axis) * pow(dot(base, cross(r->dir, axis)), 2);
	t_scl	sqrted = sqrt(sqrt1 - sqrt2);

	t_scl	front = dot(cross(r->dir, axis), cross(base, axis));
	t_scl	below = dot(cross(r->dir, axis), cross(r->dir, axis));

	t_scl	d = front + sqrted / below;
	t_scl	t = dot(axis, sb(r))
	
	// The intersect is a line ()

	// t_scl	t = dot(axis, sb())


	
}

// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
// {
// 	t_scl	height = obj->val.height;
// 	t_scl	h_half = obj->val.height / 2;
// 	t_scl	radius = obj->val.cir.radius;
// 	t_point	center = obj->val.cir.center;
// 	t_uvec	axis = obj->val.axis;

// 	t_point	b = mtv(ad(obj->val.cir.center, vec(h_half, h_half, h_half)), axis);
// 	t_point p 
// }

// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
// {
// 	t_scl	height = obj->val.height;
// 	t_scl	h_half = obj->val.height / 2;
// 	t_scl	radius = obj->val.cir.radius;
// 	// t_point	center = obj->val.cir.center;
// 	t_uvec	axis = obj->val.axis;
	
// 	t_point	C = mtv(ad(obj->val.cir.center, vec(h_half, h_half, h_half)), axis);
// 	// t_point	H = mtv(ad(obj->val.cir.center, vec(h_half, h_half, h_half)), mt(axis, -1));
// 	t_vec	w = sb(r->org, C);
// 	t_vec	v = r->dir;
// 	t_uvec	h = obj->val.axis;

// 	t_scl	a = dot(v, v) - pow(dot(v, h), 2);
// 	t_scl	b = 2 * (dot(v, w) - dot(v, h) * dot(w, h));
// 	t_scl	c = dot(w, w) - pow(dot(w, h), 2) - radius * radius;

// 	t_scl	disc = b * b - 4 * a * c;

// 	(void)t;

// 	if (disc < 0)
// 		return (FALSE);
// 	if (disc == 0)
// 	{
// 		t_scl	t = -b / (2 * a);
// 		// printf("One intersection\n");
		
// 		rec->t = t;
// 		rec->point = ray_at(r, t);

// 		if (0 <= rec->t && rec->t <= height)
// 			rec->normal = unit(sb(sb(rec->point, mt(axis, rec->t)), C));
// 		else if (-radius <= rec->t && rec->t < 0)
// 			rec->normal = dv(sb(rec->point, C), radius);
// 		else if (height < rec->t && rec->t <= height + radius)
// 			rec->normal = dv(sb(sb(rec->point, C), mt(axis, height)), radius);
// 		else if (rec->t == 0)
// 			rec->normal = mt(axis, -1);
// 		else if (rec->t == height)
// 			rec->normal = axis;

// 		rec->txtr = &obj->txtr;
// 		return (TRUE);
// 	}
// 	else
// 	{
// 		t_scl	t1 = (-b - sqrt(disc)) / (2 * a);
// 		t_scl	t2 = (-b + sqrt(disc)) / (2 * a);
// 		// printf("Two intersection\n");

// 		rec->t = fmin(t1, t2);
// 		rec->point = ray_at(r, rec->t);

// 		if (0 <= rec->t && rec->t <= height)
// 			rec->normal = unit(sb(sb(rec->point, mt(axis, rec->t)), C));
// 		else if (-radius <= rec->t && rec->t < 0)
// 			rec->normal = dv(sb(rec->point, C), radius);
// 		else if (height < rec->t && rec->t <= height + radius)
// 			rec->normal = dv(sb(sb(rec->point, C), mt(axis, height)), radius);
// 		else if (rec->t == 0)
// 			rec->normal = mt(axis, -1);
// 		else if (rec->t == height)
// 			rec->normal = axis;

// 		rec->txtr = &obj->txtr;
// 		return (TRUE);
// 	}
// }

// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
// {
// 	(void)t;
// 	// Translation and scaling to simplify calculations
// 	t_vec	oc = vec(r->org.x, r->org.y - 1, r->org.z);
// 	t_vec	d = r->dir;
// 	t_vec	o = vec(0, 0, 0);

// 	// Quadratic coefficients
// 	t_scl	a = pow(d.x, 2) + pow(d.z, 2);
// 	t_scl	b = 2 * (oc.x * d.x + oc.z * d.z);
// 	t_scl	c = pow(oc.x, 2) + pow(oc.z, 2) - pow(obj->val.cir.radius, 2);

// 	// Discriminant
// 	t_scl	discriminant = b * b - 4 * a * c;

// 	if (discriminant > 0)
// 	{
// 		// 2 intersections
// 		t_scl	t1 = (-b - sqrt(discriminant)) / (2 * 1);
// 		t_scl	t2 = (-b + sqrt(discriminant)) / (2 * 1);

// 		if (t1 > 0 && t1 <= r->dir.y)
// 		{
// 			rec->t = t1;
// 			// rec->point = mtv(ad(r->org, vec(t1, t1, t1)), r->dir);
// 			rec->point = ray_at(r, rec->t);
// 			rec->normal = vec(rec->point.x - o.x, 0, rec->point.z - o.z);
// 			printf("cylinder true 1\n");
// 			return (TRUE);
// 		}
		
// 		if (t2 > 0 && t2 <= r->dir.y)
// 		{
// 			rec->t = t2;
// 			// rec->point = mtv(ad(r->org, vec(t2, t2, t2)), r->dir);
// 			rec->point = ray_at(r, rec->t);
// 			rec->normal = vec(rec->point.x - o.x, 0, rec->point.z - o.z);
// 			printf("cylinder true 2\n");
// 			return (TRUE);
// 		}
// 	}
// 	else if (discriminant == 0)
// 	{
// 		// 1 intersections
// 		t_scl	t = -b / (2 * a);

// 		if (t > 0 && t <= r->dir.y)
// 		{
// 			rec->t = t;
// 			// rec->point = mtv(ad(r->org, vec(t, t, t)), r->dir);
// 			rec->point = ray_at(r, rec->t);
// 			rec->normal = vec(rec->point.x - o.x, 0, rec->point.z - o.z);
// 			printf("cylinder true 3\n");
// 			return (TRUE);
// 		}
// 	}
// 	// printf("cylinder false\n");
// 	return (FALSE);
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
