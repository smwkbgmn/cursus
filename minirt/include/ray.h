/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:35:59 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 09:49:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <limits.h>

# include "libft.h"
# include "vector.h"

# define PI 3.1415926535897932385
# define CLR_SCALE 255

/* ray.c */
t_ray	ray(t_point org, t_vec direc);
t_ray	ray_point(t_scl x, t_scl y, const t_camera *cam);
t_point	ray_at(const t_ray *r, t_scl t);
t_color	ray_color(const t_ray *r, t_scl depth, t_list *objs);
t_color	color(t_scl x, t_scl y, t_scl z);

/* interval.c */
t_intvl	interval(void);
t_intvl	interval_set(t_scl min, t_scl max);
t_bool	contains(t_scl x, t_intvl intvl);
t_bool	surrounds(t_scl x, t_intvl intvl);
t_scl	clamp(t_scl x, t_intvl intvl);

/* hit.c */
t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec);

/* utill.c*/
// t_scl	num_infinity(void);
// t_scl	num_pi(void);
t_scl	degrees_to_radians(t_scl degrees);
t_scl	randn(void);
t_scl	randn_range(t_scl min, t_scl max);

#endif