/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 09:48:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_image	image(t_scl aspect, t_scl width);
static t_view	viewport(const t_camera *cam);

t_camera	camera(t_scl aspect, t_scl width, t_scl samples_per_pxl, t_scl depth)
{
	t_camera	cam;

	cam.center = point(0, 0, 0);
	cam.img = image(aspect, width);
	cam.view = viewport(&cam);
	cam.sample = samples_per_pxl;
	cam.depth = depth;
	
	// printf("cam\n");
	// printf("\origin: %f, %f, %f\n", cam.origin.x, cam.origin.y, cam.origin.z);
	// printf("\tfclen: %f\n", cam.fclen);
	// printf("\n");
	
	return (cam);
}

static t_image	image(t_scl aspect, t_scl width)
{
	t_image	img;

	img.aspect = aspect;
	img.size.w = width;
	img.size.h = (int)(width / aspect);
	if (img.size.h < 1)
		img.size.h = 1;
	return (img);
}

static t_view	viewport(const t_camera *cam)
{
	t_view	view;
	
	// Dimension
	t_scl	fclen = 1.0;
	t_scl	view_h = 2.0;
	t_scl	view_w = view_h * ((t_scl)cam->img.size.w / cam->img.size.h);

	// Calculate the vectors aacross the horizontal and down the vertical view edges
	t_vec	view_grid_w = vec(view_w, 0, 0);
	t_vec	view_grid_h = vec(0, -1 * view_h, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	view.pxl.w = dv(view_grid_w, (t_scl)cam->img.size.w);
	view.pxl.h = dv(view_grid_h, (t_scl)cam->img.size.h);

	// Calculate the location of the upper left pxl
	t_point	upleft;
	upleft = sb(cam->center, vec(0, 0, fclen));
	upleft = sb(upleft, dv(view_grid_w, 2));
	upleft = sb(upleft, dv(view_grid_h, 2));

	view.pxl00 = ad(upleft, mt(ad(view.pxl.w, view.pxl.h), 0.5));

	// printf("viewport\n");
	// printf("\tsize: %f, %f\n", view.size.x, view.size.y);
	// printf("\tunit: h(%f, %f, %f), v(%f, %f, %f)\n", view.unit.h.x, view.unit.h.y, view.unit.h.z,
		// view.unit.v.x, view.unit.v.y, view.unit.v.z);
	// printf("\tdelta: h(%f, %f, %f), v(%f, %f, %f)\n", view.delta.h.x, view.delta.h.y, view.delta.h.z,
		// view.delta.v.x, view.delta.v.y, view.delta.v.z);
	// printf("\tupper_left: %f, %f, %f\n", view.upper_left.x, view.upper_left.y, view.upper_left.z);
	// printf("\tpixel00_loc: %f, %f, %f\n", view.pixel00_loc.x, view.pixel00_loc.y, view.pixel00_loc.z);
	// printf("\n");

	return (view);
}

t_point	point(t_scl x, t_scl y, t_scl z)
{
	t_point	crd;
	
	crd.x = x;
	crd.y = y;
	crd.z = z;
	return (crd);
}