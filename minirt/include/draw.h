/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:00:17 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 09:47:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdio.h>

# include "ray.h"

/* draw.c */
void		render(t_list *objs, const t_camera *cam);

/* camera.c */
t_camera	camera(t_scl aspect, t_scl width, t_scl samples_per_pxl, t_scl depth);
t_point		point(t_scl x, t_scl y, t_scl z);

#endif