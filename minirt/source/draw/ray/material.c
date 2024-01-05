/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:30:27 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/05 09:58:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	lambertian(t_color albedo, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered);
static t_bool	metal(t_color albedo, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered);

t_mtral	material(t_name name, t_color albedo)
{
	t_mtral	mtral;
	
	if (name == LMBRT)
		mtral.scatter = &lambertian;
	else
		mtral.scatter = &metal;
	mtral.albedo = albedo;
	return (mtral);
}

static t_bool	lambertian(t_color albedo, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered)
{
	t_uvec	scatter_direction = ad(rec->normal, randuv());

	// Catch degenerate scatter direcion
	if (near_zero(scatter_direction))
		scatter_direction = rec->normal;

	*scattered = ray(rec->point, scatter_direction);
	*attenuation = albedo;

	(void)r_in;
	
	return TRUE;
}

static t_bool	metal(t_color albedo, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered)
{
	t_vec	reflected = reflect(unit(r_in->direc), rec->normal);

	*scattered = ray(rec->point, reflected);
	*attenuation = albedo;

	return TRUE;
}
