/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:04:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_canvas	canvas(t_scl width, t_scl height)
{
	t_canvas	cvs;

	cvs.size.x = width;
	cvs.size.y = height;
	cvs.aspect = width / height;
	return (cvs);
}

t_camera	camera(t_canvas *cvs, t_crd crd)
{
	t_camera	cam;

	cam.crd = crd;
	cam.view.y = VIEW_HEIGHT;
	cam.view.x = cam.view.y * cvs->aspect;
	cam.len_focal = LEN_FOCAL;
	cam.horizon = vec(cam.view.x, 0, 0);
	cam.vertical = vec(0, cam.view.y, 0);
	cam.left_bottom = vsub(vsub(vsub(cam.crd, vdiv(cam.horizon, 2)), vdiv(cam.vertical, 2)), vec(0, 0, cam.len_focal));
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