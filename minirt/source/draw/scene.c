/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/11 14:13:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_camera	camera(t_point from, t_point at, t_uvec up, t_scl fov)
{
	t_camera	cam;

	cam.from = from;
	cam.at = at;
	cam.up = up;
	cam.fov = fov;

	cam.frame.w = unit(sb(cam.from, cam.at));
	cam.frame.u = unit(cross(cam.up, cam.frame.w));
	cam.frame.v = cross(cam.frame.w, cam.frame.u);
	
	return (cam);
}

t_image	image(t_scl aspect, t_scl width)
{
	t_image	img;

	img.aspect = aspect;
	img.size.x = width;
	img.size.y = (int)(width / aspect);
	if (img.size.y < 1)
		img.size.y = 1;
	return (img);
}

t_view	viewport(const t_scene *scene)
{
	t_view	view;
	
	// Dimension
	t_scl	fclen = length(sb(scene->cam.from, scene->cam.at));
	
	t_scl	theta = degrees_to_radians(scene->cam.fov);
	t_scl	h = tan(theta / 2);
	t_scl	view_h = 2 * h * fclen;
	t_scl	view_w = view_h * ((t_scl)scene->img.size.x / scene->img.size.y);

	// Calculate the vectors aacross the horizontal and down the vertical view edges
	t_vec	view_grid_w = mt(scene->cam.frame.u, view_w); // Vector across viewport horizontal edge
	t_vec	view_grid_h = mt(scene->cam.frame.v, -view_h); // Vector down viewport vertical edge
	// t_vec	view_grid_w = vec(view_w, 0, 0);
	// t_vec	view_grid_h = vec(0, -1 * view_h, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	view.pxl.u = dv(view_grid_w, (t_scl)scene->img.size.x);
	view.pxl.v = dv(view_grid_h, (t_scl)scene->img.size.y);

	// Calculate the location of the upper left pxl
	t_point	upleft;
	upleft = scene->cam.from;
	upleft = sb(upleft, mt(scene->cam.frame.w, fclen));
	upleft = sb(upleft, dv(view_grid_w, 2));
	upleft = sb(upleft, dv(view_grid_h, 2));
	// upleft = sb(scene->cam.from, vec(0, 0, fclen));
	// upleft = sb(upleft, dv(view_grid_w, 2));
	// upleft = sb(upleft, dv(view_grid_h, 2));
	
	view.pxl00 = ad(upleft, mt(ad(view.pxl.u, view.pxl.v), 0.5));

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