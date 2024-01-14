/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:30:27 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/12 09:24:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_bool	lambertian(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd);
static t_bool	metal(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd);
static t_bool	dielectric(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd);
static t_bool	light(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd);

t_mtral	material(t_name name, t_scl fuzz, t_scl ir, t_txtr txtr)
{
	t_mtral	mtral;
	
	mtral.name = name;
	if (name == MT_DIELCT) // which is has no albedo value
	{
		mtral.scatter = &dielectric;
		mtral.dielct_ir = ir;
	}
	else
	{
		if (name == MT_LMBRT)
			mtral.scatter = &lambertian;
		else if (name == MT_LIGHT)
			mtral.scatter = &light;
		else if (name == MT_METAL)
		{
			mtral.scatter = &metal;
			mtral.metal_fuzz = (fuzz * (fuzz < 1)) + (1 * !(fuzz < 1));
		}
		// mtral.albedo = albedo;
	}
	mtral.texture = txtr;
	return (mtral);
}

static t_bool	lambertian(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd)
{
	// Snell's
	t_uvec	scatter_direction = ad(rec->normal, randuv());

	// Catch degenerate scatter direcion
	if (near_zero(scatter_direction))
		scatter_direction = rec->normal;

	*sctrd = ray(rec->point, scatter_direction);
	// *atnu = mtral->albedo;
	*atnu = mtral->texture.value(&mtral->texture, rec->map.x, rec->map.y, &rec->point);

	(void)r_in;
	return TRUE;
}

static t_bool	metal(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd)
{
	t_vec	reflected = reflect(unit(r_in->direc), rec->normal);

	// *sctrd = ray(rec->point, reflected); // Without j='][]
	*sctrd = ray(rec->point, ad(reflected, mt(randuv(), mtral->metal_fuzz)));
	// *atnu = mtral->albedo;
	*atnu = mtral->texture.value(&mtral->texture, rec->map.x, rec->map.y, &rec->point);

	return TRUE;
}

// MUST CHEKC WHICH WAY IS CORRECT FOR MODELING (Phong's vs Snell's)
// Snell's
static t_scl	reflectance(t_scl cos, t_scl ref_idx);

static t_bool	dielectric(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd)
{
	*atnu = color(1.0, 1.0, 1.0);
	t_scl	refraction_ratio;
	if (rec->face)
		refraction_ratio = 1.0 / mtral->dielct_ir;
	else
		refraction_ratio = mtral->dielct_ir;

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
	// *sctrd = ray(rec->point, refracted);

	*sctrd = ray(rec->point, direction);
	
	return (TRUE);
}

// Schlick's approximation for reflectance
static t_scl	reflectance(t_scl cos, t_scl ref_idx)
{
	t_scl	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = pow(r0, 2);
	return (r0 + (1 -r0) * pow((1 - cos), 5));
}

static t_bool	light(const t_mtral *mtral, const t_ray *r_in, const t_hit *rec,
	t_color *atnu, t_ray *sctrd)
{
	(void)mtral;
	(void)r_in;
	(void)rec;
	(void)atnu;
	(void)sctrd;
	
	return (FALSE);
}