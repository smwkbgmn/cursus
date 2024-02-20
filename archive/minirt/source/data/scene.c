/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 16:48:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_size	viewport_size(t_scl fclen, const t_scene *scene);

t_camera	camera(t_point from, t_point at, t_scl fov)
{
	t_camera	cam;
	t_uvec		up;

	cam.from = from;
	cam.at = valid_normal(at);
	cam.fov = (int)fov;
	if (cam.fov == 0)
		err_usr("fov can not be zero");
	if (at.y != 0 && at.x == 0 && at.z == 0)
		up = vec(0, 0, 1);
	else
		up = vec(0, 1, 0);
	cam.frame.w = unit(sb(cam.from, ad(cam.from, cam.at)));
	cam.frame.u = unit(cross(up, cam.frame.w));
	cam.frame.v = cross(cam.frame.w, cam.frame.u);
	return (cam);
}

t_view	viewport(const t_scene *scene)
{
	t_view	view;
	t_scl	fclen;
	t_size	size;
	t_grid	grid;
	t_point	upleft;

	fclen = length(sb(scene->cam.from, scene->cam.at));
	size = viewport_size(fclen, scene);
	grid.u = mt(scene->cam.frame.u, size.x);
	grid.v = mt(scene->cam.frame.v, -size.y);
	view.pxl.u = dv(grid.u, (t_scl)scene->img.size.x);
	view.pxl.v = dv(grid.v, (t_scl)scene->img.size.y);
	upleft = scene->cam.from;
	upleft = sb(upleft, mt(scene->cam.frame.w, fclen));
	upleft = sb(upleft, dv(grid.u, 2));
	upleft = sb(upleft, dv(grid.v, 2));
	view.pxl00 = ad(upleft, mt(ad(view.pxl.u, view.pxl.v), 0.5));
	return (view);
}

static t_size	viewport_size(t_scl fclen, const t_scene *scene)
{
	t_scl	theta;
	t_scl	h;
	t_size	view;

	theta = degrees_to_radians(scene->cam.fov);
	h = tan(theta / 2);
	view.y = 2 * h * fclen;
	view.x = view.y * ((t_scl)scene->img.size.x / scene->img.size.y);
	return (view);
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

t_point	point(t_scl x, t_scl y, t_scl z)
{
	t_point	crd;

	crd.x = x;
	crd.y = y;
	crd.z = z;
	return (crd);
}
