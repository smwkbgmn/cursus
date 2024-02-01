/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:47:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/31 23:21:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "data.h"

t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec)
{
	t_hit		rec_obj;
	t_bool		does_hit;
	t_scl		closest_so_far;

	does_hit = FALSE;
	closest_so_far = t.max;
	while (objs)
	{
		if (((t_obj *)objs->content)->hit(objs->content,
				r, interval(t.min, closest_so_far), &rec_obj))
		{
			does_hit = TRUE;
			closest_so_far = rec_obj.t;
			*rec = rec_obj;
		}
		objs = objs->next;
	}
	return (does_hit);
}

void	set_face_normal(t_hit *rec, const t_ray *r, t_vec outward_normal)
{
	rec->face = dot(r->dir, outward_normal) < 0;
	if (rec->face)
		rec->normal = outward_normal;
	else
		rec->normal = mt(outward_normal, -1);
}
