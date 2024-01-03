/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/03 08:12:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	hit_object(t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec);
static void		set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r);
static void		set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal);

t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_hit	rec_tmp;
	t_bool	hit_anything = FALSE;
	t_scl	closest_so_far = t.max;

	while (objs)
	{
		if (hit_object(objs->content, r, interval_set(t.min, closest_so_far), &rec_tmp))
		{
			hit_anything = TRUE;
			closest_so_far = rec_tmp.t;
			*rec = rec_tmp;
		}
		objs = objs->next;
	}
	return (hit_anything);
}

static t_bool	hit_object(t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec)
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

	outward_normal = dv(sb(rec->point, obj->val.cir.center),
		obj->val.cir.radius);
	set_face_normal(rec, r, outward_normal);
	
	return (TRUE);
}

static void	set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r)
{
	eqa->oc = sb(r->origin, obj->val.cir.center);
	eqa->a = square(r->direc);
	eqa->b_half = dot(eqa->oc, r->direc);
	eqa->c = square(eqa->oc) - pow(obj->val.cir.radius, 2);
	
	eqa->dscr = pow(eqa->b_half, 2) - (eqa->a * eqa->c);
}

static void	set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal)
{
	// The parameter 'outward_normal' is assumed to have unit len
	rec->face = dot(r->direc, outward_normal) < 0;
	if (rec->face)
		rec->normal = outward_normal;
	else
		rec->normal = mt(outward_normal, -1);
}
