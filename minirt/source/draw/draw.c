/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 12:49:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		put_pixel(const t_render *data, int x, int y);
static t_color	shoot_ray(const t_render *data, int x, int y);
static void		cut(t_scl *pxl_color);
// static t_scl	linear_to_gamma(t_scl linear_component);

void	render(const t_render *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->scene.img.size.y)
	{
		printf("\rScanlines remaning: %d ", (int)data->scene.img.size.y - y);	
		x = 0;
		while (x < data->scene.img.size.x)
		{
			put_pixel(data, x, y);
			x++;
		}
		y++;
	}
	printf("\rDone.                      \n");

	activate_mlx(data);
}

static void	put_pixel(const t_render *data, int x, int y)
{
	t_color	pxl_color = shoot_ray(data, x, y);
	t_color_mlx	argb = 0;

	cut(&pxl_color.x);
	cut(&pxl_color.y);
	cut(&pxl_color.z);

	argb = (argb | (int)(pxl_color.x * CLR_SCALE)) << 8;
	argb = (argb | (int)(pxl_color.y * CLR_SCALE)) << 8;
	argb = (argb | (int)(pxl_color.z * CLR_SCALE));
	
	mlx_pixel_put(data->window.mlx, data->window.ptr, x, y, argb);
}

static t_color	shoot_ray(const t_render *data, int x, int y)
{
	t_point	pxl_center;
	t_ray	r;

	pxl_center = data->scene.view.pxl00;
	pxl_center = ad(pxl_center, mt(data->scene.view.pxl.u, x));
	pxl_center = ad(pxl_center, mt(data->scene.view.pxl.v, y));
	r = ray(data->scene.cam.from,
		direction(data->scene.cam.from, pxl_center));
	return (ray_color(&r, &data->world, mt(r.direc, -1)));
}

static void	cut(t_scl *rgb)
{
	// *rgb = linear_to_gamma(*rgb);
	if (*rgb > 1)
		*rgb = 1;
}

// static t_scl	linear_to_gamma(t_scl linear_component)
// {
// 	return (sqrt(linear_component));
// }
