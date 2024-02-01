/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:15:03 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 17:28:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void		put_pixel(const t_render *data, int x, int y);
static t_color	shoot_ray(const t_render *data, int x, int y);
static t_color	clamp(t_color albedo);
static t_argb	argb_albedo(t_color albedo);

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
	mlx_pixel_put(data->window.mlx, data->window.ptr, x, y,
		argb_albedo(clamp(shoot_ray(data, x, y))));
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
	return (ray_color(&r, &data->world));
}

static t_color	clamp(t_color albedo)
{
	albedo.x = fmin(albedo.x, 1.0);
	albedo.y = fmin(albedo.y, 1.0);
	albedo.z = fmin(albedo.z, 1.0);
	return (albedo);
}

static t_argb	argb_albedo(t_color albedo)
{
	t_argb	argb;

	argb = 0;
	argb = (argb | (int)(albedo.x * CLR_SCALE)) << 8;
	argb = (argb | (int)(albedo.y * CLR_SCALE)) << 8;
	argb = (argb | (int)(albedo.z * CLR_SCALE));
	return (argb);
}
