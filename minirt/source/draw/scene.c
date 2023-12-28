/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 10:52:39 by donghyu2         ###   ########.fr       */
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
	return (cvs);
}

t_camera	camera(t_canvas *cvs)
{
	t_camera	cam;

	cam.crd = coordi(0, 0, 0);
	cam.fclen = 1.0;
	
	cam.view.size.y = 2.0;
	cam.view.size.x = cam.view.size.y * (cvs->size.x / cvs->size.y);

	cam.view.grid.h = vec(cam.view.size.x, 0, 0);
	cam.view.grid.v = vec(0, -cam.view.size.y, 0);

	cam.view.delta.h = vdv(cam.view.grid.h, cvs->size.x);
	cam.view.delta.h = vdv(cam.view.grid.v, cvs->size.y);

	cam.view.upper_left = vsb(cam.crd,
		vsb(vec(0, 0, cam.fclen),
		vsb(vdv(cam.view.grid.h, 2), vdv(cam.view.grid.v, 2))));
	cam.view.pixel00_loc = vad(cam.view.upper_left,
		vmt(vad(cam.view.delta.h, cam.view.delta.v), 0.5));
	return (cam);
}

t_crd	coordi(t_scl x, t_scl y, t_scl z)
{
	t_crd	crd;
	
	crd.x = x;
	crd.y = y;
	crd.z = z;
	return (crd);
}