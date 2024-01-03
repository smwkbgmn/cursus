/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 07:30:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// DEBUGGING remove it later

#include "draw.h"

static void		write_color(t_color color, int samples_per_pxl);

void	render(t_list *objs, const t_camera *cam)
{
	int	x, y;

	printf("P3\n%d %d\n%d\n", (int)cam->img.size.w, (int)cam->img.size.h, CLR_SCALE);

	y = 0;
	while (y < cam->img.size.h)
	{
		dprintf(STDERR_FILENO, "\rScanlines remaning: %d ", (int)cam->img.size.h - y);
		
		x = 0;
		while (x < cam->img.size.w)
		{
			t_color	pxl_color = color(0, 0, 0);

			int	sample = 0;
			while (sample < cam->sample)
			{
				t_ray	r = ray_point(x, y, cam);
				pxl_color = ad(pxl_color, ray_color(&r, objs));

				sample++;
			}
			write_color(pxl_color, cam->sample);

			// t_point	pxl_center = ad(cam->view.pxl00, ad(mt(cam->view.pxl.w, (t_scl)x), mt(cam->view.pxl.h, (t_scl)y)));
			// t_vec	r_direc = sb(pxl_center, cam->center);
			// t_ray	r = ray(cam->center, r_direc);
			
			// t_color	color = ray_color(&r, objs);
			// write_color(color, cam->sample);
			
			x++;
		}
		y++;
	}
	dprintf(STDERR_FILENO, "\rDone.                \n");
}

static void	write_color(t_color pxl_color, int samples_per_pxl)
{
	t_scl	r = pxl_color.x;
	t_scl	g = pxl_color.y;
	t_scl	b = pxl_color.z;

	// Divide the color by the numver of samples
	t_scl	scale = 1.0 / samples_per_pxl;
	r *= scale;
	g *= scale;
	b *= scale;
	
	// Write the translated [0, 255] value of each color component
	t_intvl	intensity = interval_set(0.000, 0.999);
	printf("%d %d %d\n",
		(int)(256 * clamp(r, intensity)),
		(int)(256 * clamp(g, intensity)),
		(int)(256 * clamp(b, intensity)));

	// if (samples_per_pxl)
	// 	printf("%d %d %d\n",
	// 		(int)(255.999 * pxl_color.x),
	// 		(int)(255.999 * pxl_color.y),
	// 		(int)(255.999 * pxl_color.z));
}
