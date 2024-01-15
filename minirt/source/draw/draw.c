/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/15 17:15:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

// static void		write_color(t_color color, int samples_per_pxl);
static void	write_color(t_color pxl_color, int sample, t_bool aliasing);

void	render(t_list *objs, const t_scene *scene)
{
	int	x, y;

	printf("P3\n%d %d\n%d\n", (int)scene->img.size.x, (int)scene->img.size.y, CLR_SCALE);

	y = 0;
	while (y < scene->img.size.y)
	{
		dprintf(2, "\rScanlines remaning: %d ", (int)scene->img.size.y - y);
		
		x = 0;
		while (x < scene->img.size.x)
		{
			// ANTIALIAS SAMPLING
			// t_color	pxl_color = color(0, 0, 0);

			// int	sample = 0;
			// while (sample < scene->sample)
			// {
			// 	t_ray	r = ray_point(x, y, scene);
			// 	pxl_color = ad(pxl_color, ray_color(&r, scene->depth, objs));

			// 	sample++;
			// }
			// write_color(pxl_color, scene->sample, FALSE);

			// PLAIN WAY
			// t_point	pxl_center = ad(ad(scene->view.pxl00, mt(scene->view.pxl.u, x)), mt(scene->view.pxl.v, y));
			t_point	pxl_center = scene->view.pxl00;
			pxl_center = ad(pxl_center, mt(scene->view.pxl.u, x));
			pxl_center = ad(pxl_center, mt(scene->view.pxl.v, y));
			t_vec	ray_direction = sb(pxl_center, scene->cam.from);
			// t_ray	r = ray(scene->cam.from, ray_direction);
			t_ray	r = ray(scene->cam.from, ray_direction);

			t_color	pxl_color = ray_color(&r, scene->depth, objs);
			write_color(pxl_color, scene->sample, TRUE);

			x++;
		}
		y++;
	}
	dprintf(2, "\rDone.                \n");
}

static t_scl	linear_to_gamma(t_scl linear_component);
static void		antialiasing(t_color pxl_color, int sample);

static void	write_color(t_color pxl_color, int sample, t_bool aliasing)
{
	if (aliasing)
	{
		pxl_color.x = linear_to_gamma(pxl_color.x);
		pxl_color.y = linear_to_gamma(pxl_color.y);
		pxl_color.z = linear_to_gamma(pxl_color.z);

		printf("%d %d %d\n",
			(int)(255.999 * pxl_color.x),
			(int)(255.999 * pxl_color.y),
			(int)(255.999 * pxl_color.z));

		// dprintf(2, "%d %d %d\n",
		// 	(int)(255.999 * pxl_color.x),
		// 	(int)(255.999 * pxl_color.y),
		// 	(int)(255.999 * pxl_color.z));
	}
			
	else
		antialiasing(pxl_color, sample);

}

static void	antialiasing(t_color pxl_color, int sample)
{
	t_scl	r = pxl_color.x;
	t_scl	g = pxl_color.y;
	t_scl	b = pxl_color.z;

	// dprintf(2, "%.2f %.2f %.2f\n", pxl_color.x, pxl_color.y, pxl_color.z);

	// Divide the color by the numver of samples
	t_scl	scale = 1.0 / sample;
	r *= scale;
	g *= scale;
	b *= scale;
	
	// Apply the linear to gamma transform
	r = linear_to_gamma(r);
	g = linear_to_gamma(g);
	b = linear_to_gamma(b);

	// Write the translated [0, 255] value of each color component
	t_intvl	intensity = interval_set(0.000, 0.999);
	printf("%d %d %d\n",
		(int)(256 * clamp(r, intensity)),
		(int)(256 * clamp(g, intensity)),
		(int)(256 * clamp(b, intensity)));

	// dprintf(2, "%d %d %d\n",
	// 	(int)(256 * clamp(r, intensity)),
	// 	(int)(256 * clamp(g, intensity)),
	// 	(int)(256 * clamp(b, intensity)));
}

static t_scl	linear_to_gamma(t_scl linear_component)
{
	return (sqrt(linear_component));
}
