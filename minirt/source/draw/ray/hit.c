/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:21:15 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/30 14:18:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_bool	hit_sphere(const t_crd center, t_scl radius, const t_ray r)
{
	t_vec	oc = sb(r.pos, center);
	t_scl	a = dot(r.direc, r.direc);
	t_scl	b = 2.0 * dot(oc, r.direc);
	t_scl	c = dot(oc, oc) - radius * radius;
	t_scl 	discriminant = (b * b) - (4.0 * a * c);
	return (discriminant >= 0);
}
