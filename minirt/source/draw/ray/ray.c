/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:13:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/14 11:14:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "ray.h"

static t_vec	pxl_sample_square(t_grid pxl);
// static t_color	emitted(const t_mtral *mtral, t_scl u, t_scl v, const t_point *p);

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
	// t_point	pxl_center = ad(cam->view.pxl00, ad(mt(cam->view.pxl.w, (t_scl)x), mt(cam->view.pxl.v, (t_scl)y)));
	t_point	pxl_center = scene->view.pxl00;
	pxl_center = ad(pxl_center, mt(scene->view.pxl.u, x));
	pxl_center = ad(pxl_center, mt(scene->view.pxl.v, y));
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
	/* OBJECT */
	t_hit	rec;
	
	// If we've exceeded the ray bounce limit, no more light is gathered
	if (depth <= 0)
		return (color(0, 0, 0));

	// WITH LIGHT OBJECT
	// // If the ray hits nothing, return the background color
	// if (!hit(objs, r, interval_set(0.001, INFINITY), &rec))
	// 	return (color(0, 0, 0));

	// t_ray	sctrd;
	// t_color	atnu;
	// t_color	from_emission = emitted(rec.mtral, rec.map.x, rec.map.y, &rec.point);

	// if (!rec.mtral->scatter(rec.mtral, r, &rec, &atnu, &sctrd))
	// 	return (from_emission);

	// t_color	from_scatter = mtv(atnu, ray_color(&sctrd, depth - 1, objs));
	// return (ad(from_emission, from_scatter));

	// WITHOUT LIGHT OBJECT
	if (hit(objs, r, interval_set(0.001, INFINITY), &rec))
	{
		// MATERIAL COLOR (Phong's)
		t_color	rst = rec.mtral->texture.albedo;

		if (rec.t < 0)
			rst = color(0, 0, 0);
		else
		{
			t_scl	diff;
			t_scl	dotted;

			dotted = dot(rec.normal, unit(sb(r->origin, rec.point)));
			if (dotted > 0)
				diff = dotted;
			else
				diff = 0;
			
			rst = mt(rst, diff);
		}
		return (rst);
		
		
		// MATERIAL COLOR (Snell's)
		// t_ray	sctrd;
		// t_color	atnu;

		// if (rec.mtral->scatter(rec.mtral, r, &rec, &atnu, &sctrd))
		// {
		// 	dprintf(2, "\tHitted some object at(%f, %f, %f), color(%f, %f, %f)\n",
		// 		rec.point.x, rec.point.y, rec.point.z,
		// 		atnu.x, atnu.y, atnu.z);
		// 	return (mtv(atnu, ray_color(&sctrd, depth - 1, objs)));
		// 	// return (atnu);
		// }

		// DIFFUESE
		// t_vec	direction = randv_on_hemisphere(rec.normal);
		// t_ray	r_tmp = ray(rec.point, direction);
		// return (mtv(ray_color(&r_tmp, depth - 1, objs), rec.mtral->texture.albedo));
		// return (mt(ray_color(&r_tmp, depth - 1, objs), 0.5));
		
		// COSTANT COLOR
		// return (mt(ad(rec.normal, color(1, 1, 1)), 0.5));
	}

	// dprintf(2, "\tnow hit rec point(%f, %f, %f), depth %f\n",
	// 	rec.point.x,
	// 	rec.point.y,
	// 	rec.point.z,
	// 	depth);

	/* BACKGROUND */
	// SKY
	// t_uvec	unit_direc = unit(r->direc);
	// t_scl	scale = 0.5 * (unit_direc.y + 1.0);
	// return (ad(mt(color(1.0, 1.0, 1.0), 1.0 - scale), mt(color(0.5, 0.7, 1.0), scale)));

	// BLACK
	// if (depth == 50)
	// {
	// 	dprintf(2, "\t\tMissed all at(%f, %f, %f)\n",
	// 		rec.point.x, rec.point.y, rec.point.z);
	// 	return (color(0, 0, 0));
	// }
	// else
	// {
	// 	dprintf(2, "\t\tEnd of diffuseing at(%f, %f, %f)\n",
	// 		rec.point.x, rec.point.y, rec.point.z);
	// 	return (color(1, 1, 1));
	// }
	return (color(0, 0, 0));
}

// Returns a random point in the square surrounding a pixel at the origin
static t_vec	pxl_sample_square(t_grid pxl)
{
	t_scl	px = -0.5 + randn();
	t_scl	py = -0.5 + randn();
	return (ad(mt(pxl.u, px), mt(pxl.v, py)));
}

// static t_color	emitted(const t_mtral *mtral, t_scl u, t_scl v, const t_point *p)
// {
// 	if (mtral->name == MT_LIGHT)
// 		return (mtral->texture.value(&mtral->texture, u, v, p));
// 	// return (color(0, 0, 0));
// 	return (color(0, 0, 0));
// }

t_color	color(t_scl x, t_scl y, t_scl z)
{
	t_color	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}