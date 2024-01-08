/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:30:27 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/06 14:29:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	lambertian(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered);
static t_bool	metal(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered);
static t_bool	dielectric(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered);
static t_scl	reflectance(t_scl cos, t_scl ref_idx);

t_mtral	material(t_name name, t_color albedo, t_scl fuzz, t_scl ir)
{
	t_mtral	mtral;
	
	if (name < 5)
	{
		if (name == LMBRT)
			mtral.scatter = &lambertian;
		else if (name == METAL)
		{
			mtral.scatter = &metal;
			if (fuzz < 1)
				mtral.fuzz = fuzz;
			else
				mtral.fuzz = 1;
		}
		mtral.albedo = albedo;
	}
	else
	{
		mtral.scatter = &dielectric;
		mtral.ir = ir;
	}
	return (mtral);
}

static t_bool	lambertian(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered)
{
	t_uvec	scatter_direction = ad(rec->normal, randuv());

	// Catch degenerate scatter direcion
	if (near_zero(scatter_direction))
		scatter_direction = rec->normal;

	*scattered = ray(rec->point, scatter_direction);
	*attenuation = mtral->albedo;

	(void)r_in;
	
	return TRUE;
}

static t_bool	metal(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered)
{
	t_vec	reflected = reflect(unit(r_in->direc), rec->normal);

	// *scattered = ray(rec->point, reflected); // Without j='][]
	*scattered = ray(rec->point, ad(reflected, mt(randuv(), mtral->fuzz)));
	*attenuation = mtral->albedo;

	return TRUE;
}

static t_bool	dielectric(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *attenuation, t_ray *scattered)
{
	*attenuation = color(1.0, 1.0, 1.0);
	t_scl	refraction_ratio;
	if (rec->face)
		refraction_ratio = 1.0 / mtral->ir;
	else
		refraction_ratio = mtral->ir;

	t_uvec	unit_direc = unit(r_in->direc);
	t_scl	cos_theta = fmin(dot(mt(unit_direc, -1), rec->normal), 1.0);
	t_scl	sin_theta = sqrt(1.0 - pow(cos_theta, 2));
	
	t_bool	cannot_refract = (refraction_ratio * sin_theta > 1.0);
	t_uvec	direction;
	// if (cannot_refract)
	if (cannot_refract || reflectance(cos_theta, refraction_ratio) > randn())
		direction = reflect(unit_direc, rec->normal);
	else
		direction = refract(&unit_direc, &rec->normal, refraction_ratio);

	// t_vec	refracted = refract(&unit_direc, &rec->normal, refraction_ratio);
	// *scattered = ray(rec->point, refracted);

	*scattered = ray(rec->point, direction);
	
	return (TRUE);
}

// Schlick's approximation for reflectance
static t_scl	reflectance(t_scl cos, t_scl ref_idx)
{
	t_scl	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = pow(r0, 2);
	return (r0 + (1 -r0) * pow((1 - cos), 5));
}
