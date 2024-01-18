/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:34:37 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/18 21:26:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		set_color(const t_hit *rec, t_color *dim, t_color *high, t_phong phong);
static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light);
static t_phong	get_phong(const t_hit *rec, const t_light *light, t_uvec dir_view);
static t_scl	get_specular(t_uvec normal, t_uvec dir_light, t_uvec dir_view);

t_color	phong(const t_hit *rec, const t_world *world, t_uvec dir_view)
{
	t_color	dim;
	t_color	high;
	t_list	*lights;

	dim = world->ambient;
	high = color(0, 0, 0);
	lights = world->lights;
	while (lights)
	{
		if (meet_light(rec, world->objs, lights->content))
			set_color(rec, &dim, &high,
				get_phong(rec, lights->content, dir_view));
		lights = lights->next;
	}
	return (ad(mtv(rec->mtral->texture.albedo, dim), high));
}

static void	set_color(const t_hit *rec, t_color *dim, t_color *high, t_phong phong)
{
	if (rec->t >= 0)
		*dim = ad(*dim, mt(phong.light, phong.diffuse));
	*high = ad(*high, mt(mt(mt(phong.light,
		phong.specular), SPEC_INTENS), phong.diffuse));
}

static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light)
{
	t_ray	ray_to_light = ray(rec->point, sb(light->pos, rec->point));
	t_scl	len_to_light = length(sb(light->pos, rec->point));
	
	if (hit(objs, &ray_to_light, interval_set(0.001, len_to_light), NULL))
		return FALSE;
	return TRUE;
}

static t_phong	get_phong(const t_hit *rec, const t_light *light, t_uvec dir_view)
{
	t_phong	phong;
	t_uvec	dir_light;

	dir_light = unit(sb(light->pos, rec->point));
	phong.diffuse = fmax(dot(rec->normal, dir_light), 0.0);
	phong.specular = get_specular(rec->normal, dir_light, dir_view);
	phong.light = light->albedo;
	return (phong);
}

static t_scl	get_specular(t_uvec normal, t_uvec dir_light, t_uvec dir_view)
{
	t_uvec	dir_halfway;
	t_scl	theta_reflect_view;
	
	dir_halfway = unit(ad(dir_light, dir_view));
	theta_reflect_view = dot(normal, dir_halfway);
	return (pow(fmax(theta_reflect_view, 0.0), SPEC_SHINE));
}

/* ORIGINAL */

// static t_color	diffuse(const t_light *light, const t_hit *rec);
// static t_color	specular(const t_hit *rec, const t_light *light, t_uvec dir_view);

// t_color	phong(const t_hit *rec, const t_world *world, t_uvec dir_view)
// {
// 	t_list	*lights = world->lights;
// 	t_color	diff = world->ambient;
// 	t_color	spec = color(0, 0, 0);

// 	while (lights)
// 	{
// 		if (meet_light(rec, world->objs, lights->content))
// 		{
// 			if (rec->t >= 0)
// 				diff = ad(diff, diffuse(lights->content, rec));
// 			spec = ad(spec, specular(rec, lights->content, dir_view));
// 		}

// 		lights = lights->next;
// 	}
// 	return (ad(mtv(rec->mtral->texture.albedo, diff), spec));
// }

// static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light)
// {
// 	t_ray	ray_to_light = ray(rec->point, sb(light->pos, rec->point));
// 	t_scl	len_to_light = length(sb(light->pos, rec->point));
	
// 	if (hit(objs, &ray_to_light, interval_set(0.001, len_to_light), NULL))
// 		return FALSE;
// 	return TRUE;
// }

// static t_color	diffuse(const t_light *light, const t_hit *rec)
// {
// 	t_uvec	dir_to_light = unit(sb(light->pos, rec->point));
// 	t_scl	theta = fmax(dot(rec->normal, dir_to_light), 0.0);

// 	return (mt(light->albedo, theta));
// }

// static t_color	specular(const t_hit *rec, const t_light *light, t_uvec dir_view)
// {
// 	t_vec	dir_to_light = unit(sb(light->pos, rec->point));
// 	t_vec	dir_halfway = unit(ad(dir_to_light, dir_view));

// 	t_scl	theta_reflect_view = dot(rec->normal, dir_halfway);
// 	t_scl	spec = pow(fmax(theta_reflect_view, 0.0), SPEC_SHINE);
	 
// 	t_scl	theta_light_normal = fmax(dot(rec->normal, dir_to_light), 0.0);

// 	return (mt(mt(mt(light->albedo, spec), SPEC_INTENS), theta_light_normal));
// }
