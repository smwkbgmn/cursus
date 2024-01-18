/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:34:37 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/18 19:36:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light);
static t_color	diffuse(const t_light *light, const t_hit *rec);
static t_color	specular(const t_hit *rec, const t_light *light, t_uvec dir_view);

t_color	phong(const t_hit *rec, const t_world *world, t_uvec dir_view)
{
	t_list	*lights = world->lights;
	t_color	diff = world->ambient;
	t_color	spec = color(0, 0, 0);

	while (lights)
	{
		if (meet_light(rec, world->objs, lights->content))
		{
			if (rec->t >= 0)
				diff = ad(diff, diffuse(lights->content, rec));
			spec = ad(spec, specular(rec, lights->content, dir_view));
		}

		lights = lights->next;
	}
	return (ad(mtv(rec->mtral->texture.albedo, diff), spec));
}

static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light)
{
	t_ray	ray_to_light = ray(rec->point, sb(light->pos, rec->point));
	t_scl	len_to_light = length(sb(light->pos, rec->point));
	
	if (hit(objs, &ray_to_light, interval_set(0.001, len_to_light), NULL))
		return FALSE;
	return TRUE;
}

static t_color	diffuse(const t_light *light, const t_hit *rec)
{
	t_uvec	dir_to_light = unit(sb(light->pos, rec->point));
	t_scl	theta = fmax(dot(rec->normal, dir_to_light), 0.0);

	return (mt(light->albedo, theta));
}

static t_color	specular(const t_hit *rec, const t_light *light, t_uvec dir_view)
{
	t_vec	dir_to_light = unit(sb(light->pos, rec->point));
	t_vec	dir_halfway = unit(ad(dir_to_light, dir_view));

	t_scl	theta_reflect_view = dot(rec->normal, dir_halfway);
	t_scl	spec = pow(fmax(theta_reflect_view, 0.0), SPEC_SHINE);
	 
	t_scl	theta_light_normal = fmax(dot(rec->normal, dir_to_light), 0.0);

	return (mt(mt(mt(light->albedo, spec), SPEC_INTENS), theta_light_normal));
}
