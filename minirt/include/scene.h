/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:08:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:15:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"

# define VIEW_HEIGHT 1;
# define LEN_FOCAL	2;

// scene.c
t_canvas	canvas(double width, double height);
t_camera	camera(t_canvas *canvas, t_crd crd);
t_crd		coordi(t_scl x, t_scl y, t_scl z);

#endif