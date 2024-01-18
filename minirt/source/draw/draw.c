/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/18 21:27:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		write_color(t_color pxl_color);
static t_scl	linear_to_gamma(t_scl linear_component);

void	render(const t_scene *scene, const t_world *world)
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
			// t_point	pxl_center = ad(ad(scene->view.pxl00, mt(scene->view.pxl.u, x)), mt(scene->view.pxl.v, y));
			t_point	pxl_center = scene->view.pxl00;
			pxl_center = ad(pxl_center, mt(scene->view.pxl.u, x));
			pxl_center = ad(pxl_center, mt(scene->view.pxl.v, y));
			t_vec	ray_direction = sb(pxl_center, scene->cam.from);
			t_ray	r = ray(scene->cam.from, ray_direction);

			t_color	pxl_color = ray_color(&r, world, unit(sb(scene->cam.from, scene->cam.at)));
			write_color(pxl_color);

			x++;
		}
		y++;
	}
	dprintf(2, "\rDone.                \n");
}

static void	cut(t_scl *pxl_color);

static void	write_color(t_color pxl_color)
{
	pxl_color.x = linear_to_gamma(pxl_color.x);
	pxl_color.y = linear_to_gamma(pxl_color.y);
	pxl_color.z = linear_to_gamma(pxl_color.z);

	cut(&pxl_color.x);
	cut(&pxl_color.y);
	cut(&pxl_color.z);

	printf("%d %d %d\n",
		(int)(255.999 * pxl_color.x),
		(int)(255.999 * pxl_color.y),
		(int)(255.999 * pxl_color.z));
}

static t_scl	linear_to_gamma(t_scl linear_component)
{
	return (sqrt(linear_component));
}

static void	cut(t_scl *pxl_color)
{
	if (*pxl_color > 1)
		*pxl_color = 1;
}