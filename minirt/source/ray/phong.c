/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:34:37 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 07:17:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light);
static t_phong	get_phong(const t_hit *rec, const t_light *light, t_uvec dir_view);
static t_scl	get_specular(t_uvec normal, t_uvec dir_light, t_uvec dir_view);
static void		set_color(t_color *dim, t_color *high, t_phong phong, t_scl len_to_light);
static t_color	light_attenuation(t_color light, t_scl len_to_light);

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
			set_color(&dim, &high,
				get_phong(rec, lights->content, dir_view),
					length(sb(((t_light *)lights->content)->pos, rec->point)));
		lights = lights->next;
	}
	return (ad(mtv(rec->txtr->value(rec), dim), high));
}

static t_bool	meet_light(const t_hit *rec, t_list *objs, const t_light *light)
{
	t_ray	ray_to_light = ray(rec->point, sb(light->pos, rec->point));
	t_scl	len_to_light = length(sb(light->pos, rec->point));
	t_hit	rec_to_light;
	
	if (hit(objs, &ray_to_light, interval(0.001, len_to_light), &rec_to_light))
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

static void	set_color(t_color *dim, t_color *high, t_phong phong, t_scl len_to_light)
{
	// (void)len_to_light;
	*dim = ad(*dim, mt(light_attenuation(phong.light, len_to_light), phong.diffuse));
	// *dim = ad(*dim, mt(phong.light, phong.diffuse));

	// (void)high;
	// *high = ad(*high, mt(mt(mt(phong.light,
	*high = ad(*high, mt(mt(mt(light_attenuation(phong.light, len_to_light),
		phong.specular), SPEC_INTENS), phong.diffuse));
}

static t_color	light_attenuation(t_color light, t_scl len_to_light)
{
	// return (mt(light, fmin(fmax(7.5 / len_to_light, 0.0), 1.0)));
	return (mt(light, fmax(5 / len_to_light, 0.0)));
}