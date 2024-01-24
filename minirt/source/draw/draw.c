/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 11:05:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		write_color(t_color pxl_color);
// static t_scl	linear_to_gamma(t_scl linear_component);
static void	put_pxl(t_color pxl_color, const t_win *win, int x, int y);

void	render(const t_render *data)
{
	int	a = 1;
	if (a)
	{
		int				x, y;
		const	t_world	*world = &data->world;
		const	t_scene	*scene = &data->scene;
		// const	t_win	*window = &data->window;

		t_point			pxl_center;
		t_vec			ray_dir;
		t_ray			r;

		t_color			pxl_color;

		y = 0;
		while (y < scene->img.size.y)
		{
			dprintf(2, "\rScanlines remaning: %d ", (int)scene->img.size.y - y);	
			
			x = 0;
			while (x < scene->img.size.x)
			{
				pxl_center = scene->view.pxl00;
				pxl_center = ad(pxl_center, mt(scene->view.pxl.u, x));
				pxl_center = ad(pxl_center, mt(scene->view.pxl.v, y));
				ray_dir = sb(pxl_center, scene->cam.from);
				r = ray(scene->cam.from, ray_dir);

				pxl_color = ray_color(&r, world, mt(r.direc, -1));
				// put_pxl(pxl_color, window, x, y);
				put_pxl(pxl_color, &data->window, x, y);
				x++;
			}
			y++;
		}
	}
	else
	{
	const t_world	*world = &data->world;
	const t_scene	*scene = &data->scene;
	int	x, y;

	printf("P3\n%d %d\n%d\n", (int)scene->img.size.x, (int)scene->img.size.y, CLR_SCALE);

	y = 0;
	while (y < scene->img.size.y)
	{
		dprintf(2, "\rScanlines remaning: %d ", (int)scene->img.size.y - y);
		
		x = 0;
		while (x < scene->img.size.x)
		{
			t_point	pxl_center = scene->view.pxl00;
			pxl_center = ad(pxl_center, mt(scene->view.pxl.u, x));
			pxl_center = ad(pxl_center, mt(scene->view.pxl.v, y));
			t_vec	ray_direction = sb(pxl_center, scene->cam.from);
			t_ray	r = ray(scene->cam.from, ray_direction);

			// t_color	pxl_color = ray_color(&r, world, unit(sb(scene->cam.from, scene->cam.at)));
			t_color	pxl_color = ray_color(&r, world, unit(mt(ray_direction, -1)));
			write_color(pxl_color);

			x++;
		}
		y++;
	}
	dprintf(2, "\rDone.                \n");
	}
}

static void	cut(t_scl *pxl_color);

static void	put_pxl(t_color pxl_color, const t_win *win, int x, int y)
{
	t_color_mlx	argb = 0;

	cut(&pxl_color.x);
	cut(&pxl_color.y);
	cut(&pxl_color.z);

	// if (pxl_color.x && pxl_color.y && pxl_color.z)
	// {
	// 	printf("from color (%.2f, %.2f, %.2f)\n",
	// 		pxl_color.x, pxl_color.y, pxl_color.z);
	// 	rgb = (rgb | r) << 8;
	// 	printf("now rgb [%08X]\n", rgb);
	// 	rgb = (rgb | g) << 8;
	// 	printf("now rgb [%08X]\n", rgb);
	// 	rgb = (rgb | b);
	// 	printf("now rgb [%08X]\n\n", rgb);
	// }

	argb = (argb | (int)(pxl_color.x * CLR_SCALE)) << 8;
	argb = (argb | (int)(pxl_color.y * CLR_SCALE)) << 8;
	argb = (argb | (int)(pxl_color.z * CLR_SCALE));
	
	mlx_pixel_put(win->mlx, win->ptr, x, y, argb);
}

static void	write_color(t_color pxl_color)
{
	// pxl_color.x = linear_to_gamma(pxl_color.x);
	// pxl_color.y = linear_to_gamma(pxl_color.y);
	// pxl_color.z = linear_to_gamma(pxl_color.z);

	printf("%d %d %d\n",
		(int)(255.999 * pxl_color.x),
		(int)(255.999 * pxl_color.y),
		(int)(255.999 * pxl_color.z));
}

// static t_scl	linear_to_gamma(t_scl linear_component)
// {
// 	return (sqrt(linear_component));
// }

static void	cut(t_scl *rgb)
{
	if (*rgb > 1)
		*rgb = 1;
}
