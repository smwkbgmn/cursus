/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 14:44:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	hit_object(t_obj *obj, const t_ray *r, t_scl t[2], t_hit *rec);
static void		set_equation(t_eqa *eqa, const t_obj *obj, const t_ray *r);
static void		set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal);

// t_bool	hit(t_list *objs, const t_ray *r, t_scl t[2], t_hit *rec)
t_bool	hit(t_hitbl able, t_hit *rec)
{
	t_hit	rec_tmp;
	t_bool	hit_anything = FALSE;

	while (able.objs)
	{
		if (hit_object(able.objs->content, able.r, able.t, &rec_tmp))
		{
			hit_anything = TRUE;
			able.t[MAX] = rec_tmp.t;
			*rec = rec_tmp;
		}
		able.objs = able.objs->next;
	}
	return (hit_anything);
}

static t_bool	hit_object(t_obj *obj, const t_ray *r, t_scl t[2], t_hit *rec)
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
	if (root <= t[MIN] || t[MAX] <= root)
	{
		root = (-eqa.b_half + sqrtd) / eqa.a;
		if (root <= t[MIN] || t[MAX] <= root)
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
