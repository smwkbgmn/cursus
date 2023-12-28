/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:08:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 09:49:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

// scene.c
t_canvas	canvas(void);
t_camera	camera(t_canvas *cvs);
t_crd		coordi(t_scl x, t_scl y, t_scl z);
// t_canvas	canvas(double width, double height);
// t_camera	camera(t_canvas *canvas, t_crd crd);

#endif