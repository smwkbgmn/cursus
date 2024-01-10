/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/10 13:17:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_vec	pxl_sample_square(t_grid pxl);
static t_color	emitted(const t_mtral *mtral, t_scl u, t_scl v, const t_point *p);

t_ray	ray(t_point origin, t_vec direc)
{
	t_ray	r;

	r.origin = origin;
	r.direc = direc;
	return (r);
}

// Get a randomly sampled camera ray for the pixel at location x, y
t_ray	ray_point(t_scl x, t_scl y, const t_scene *scene)
{
	// t_point	pxl_center = ad(cam->view.pxl00, ad(mt(cam->view.pxl.w, (t_scl)x), mt(cam->view.pxl.h, (t_scl)y)));
	t_point	pxl_center = scene->view.pxl00;
	pxl_center = ad(pxl_center, mt(scene->view.pxl.w, x));
	pxl_center = ad(pxl_center, mt(scene->view.pxl.h, y));
	t_vec	pxl_sample = ad(pxl_center, pxl_sample_square(scene->view.pxl));

	t_point	r_origin = scene->cam.from;
	t_vec	r_direc = sb(pxl_sample, r_origin);

	return (ray(r_origin, r_direc));
}

t_point	ray_at(const t_ray *r, t_scl t)
{
	return (ad(r->origin, mt(r->direc, t)));
}

t_color	ray_color(const t_ray *r, t_scl depth, t_list *objs)
{
	// With light object
	// SPHERE
	t_hit	rec;
	
	// If we've exceeded the ray bounce limit, no more light is gathered
	if (depth <= 0)
		return (color(0, 0, 0));

	// If the ray hits nothing, return the background color
	if (!hit(objs, r, interval_set(0.001, INFINITY), &rec))
		return (color(0, 0, 0));
		
	t_ray	scattered;
	t_color	attenuation;
	t_color	from_emission;
	
	if (rec.mtral->name == MT_LIGHT)
		from_emission = emitted(rec.mtral, rec.tx_u, rec.tx_v, &rec.point);
	else
		from_emission = color(0, 0, 0);

	if (rec.mtral->name == MT_LIGHT ||
		!rec.mtral->scatter(rec.mtral, r, &rec, &attenuation, &scattered))
		return (from_emission);

	t_color	from_scatter = mtv(attenuation, ray_color(&scattered, depth - 1, objs));
	return (ad(from_emission, from_scatter));

	// No light object
	// if (hit(objs, r, interval_set(0.001, INFINITY), &rec))
	// {
	// 	// MATERIAL
	// 	t_ray	scattered;
	// 	t_color	attenuation;

	// 	if (rec.mtral->scatter(rec.mtral, r, &rec, &attenuation, &scattered))
	// 		return (mtv(attenuation, ray_color(&scattered, depth - 1, objs)));
	// 	return (color(0, 0, 0));
	// }

	// // SKY
	// t_uvec	unit_direc = unit(r->direc);
	// t_scl	scale = 0.5 * (unit_direc.y + 1.0);
	// return (ad(mt(color(1.0, 1.0, 1.0), 1.0 - scale), mt(color(0.5, 0.7, 1.0), scale)));
}

// Returns a random point in the square surrounding a pixel at the origin
static t_vec	pxl_sample_square(t_grid pxl)
{
	t_scl	px = -0.5 + randn();
	t_scl	py = -0.5 + randn();
	return (ad(mt(pxl.w, px), mt(pxl.h, py)));
}

static t_color	emitted(const t_mtral *mtral, t_scl u, t_scl v, const t_point *p)
{
	return (mtral->texture.value(&mtral->texture, u, v, p));
}

t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}