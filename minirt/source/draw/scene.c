/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 07:01:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_canvas	canvas(void)
{
	t_canvas	cvs;

	cvs.aspect = 16.0 / 9.0;
	cvs.size.x = 400;
	cvs.size.y = (int)(cvs.size.x / cvs.aspect);
	if (cvs.size.y < 1)
		cvs.size.y = 1;
		
	// printf("canvas\n");
	// printf("\tsize: %d, %d\n", (int)cvs.size.x, (int)cvs.size.y);
	// printf("\n");
	
	return (cvs);
}

t_camera	camera(void)
{
	t_camera	cam;

	cam.origin = point(0, 0, 0);
	cam.fclen = 1.0;

	// printf("cam\n");
	// printf("\origin: %f, %f, %f\n", cam.origin.x, cam.origin.y, cam.origin.z);
	// printf("\tfclen: %f\n", cam.fclen);
	// printf("\n");
	
	return (cam);
}

t_view	viewport(t_canvas *cvs, t_camera *cam)
{
	t_view	view;

	view.size.y = 2.0;
	view.size.x = view.size.y * (cvs->size.x / cvs->size.y);

	view.unit.w = vec(view.size.x, 0, 0);
	view.unit.h = vec(0, -view.size.y, 0);

	view.delta.w = dv(view.unit.w, cvs->size.x);
	view.delta.h = dv(view.unit.h, cvs->size.y);

	view.upper_left = sb(cam->origin,
		sb(vec(0, 0, cam->fclen),
		sb(dv(view.unit.w, 2), dv(view.unit.h, 2))));
	view.pixel00_loc = ad(view.upper_left,
		mt(ad(view.delta.w, view.delta.h), 0.5));
	
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