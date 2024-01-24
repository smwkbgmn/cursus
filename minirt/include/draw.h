/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:00:17 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 09:21:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdio.h>

# include "ray.h"
# include "mlx.h"

/* draw.c */
void	render(const t_render *data);

/* scene.c */
t_camera	camera(t_point from, t_point at, t_scl fov);
t_image		image(t_scl aspect, t_scl width);
t_view		viewport(const t_scene *scene);
t_point		point(t_scl x, t_scl y, t_scl z);

/* object.c */
t_light	*light(t_point position, t_color rgb, t_scl bright);
t_obj	*plane(t_point point_on_plane, t_uvec normal, t_txtr txtr);
t_obj	*sphere(t_circle cir, t_txtr txtr);
t_obj	*cylinder(t_circle cir, t_scl height, t_uvec axis, t_txtr txtr);
t_circle	circle(t_point center, t_scl radius);
t_color	albedo_rgb(t_color rgb, t_scl bright);

#endif