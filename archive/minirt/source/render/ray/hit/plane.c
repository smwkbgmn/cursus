/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:18:08 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 01:00:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_bool	hit_plane(t_obj *obj, const t_ray *r, t_intvl ray_t, t_hit *rec)
{
	t_scl	denom;
	t_scl	d;
	t_scl	t;

	denom = dot(obj->val.sqr.normal, r->dir);
	if (fabs(denom) < 1e-8)
		return (FALSE);
	d = dot(obj->val.sqr.point, obj->val.sqr.normal);
	t = (d - dot(obj->val.sqr.normal, r->org)) / denom;
	if (!contains(t, ray_t))
		return (FALSE);
	rec->t = t;
	rec->point = ray_at(r, t);
	rec->txtr = &obj->txtr;
	set_face_normal(rec, r, obj->val.sqr.normal);
	return (TRUE);
}
