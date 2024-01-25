/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:35:59 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 07:15:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <limits.h>

# include "libft.h"
# include "vector.h"

// # define PI 3.1415926535897932385
# define PI 3.1415926

# define CLR_SCALE 255
# define SPEC_INTENS 0.45
# define SPEC_SHINE 5

// ray.c
t_ray	ray(t_point org, t_vec direc);
t_point	ray_at(const t_ray *r, t_scl t);
t_color	ray_color(const t_ray *r, const t_world *world, t_uvec dir_view);
t_color	color(t_scl x, t_scl y, t_scl z);

// interval.c
// t_intvl	interval(void);
// t_intvl	interval_set(t_scl min, t_scl max);
t_intvl	interval(t_scl min, t_scl max);
t_bool	contains(t_scl x, t_intvl intvl);
t_bool	surrounds(t_scl x, t_intvl intvl);
t_scl	clamp(t_scl x, t_intvl intvl);

// phong.c
t_color	phong(const t_hit *rec, const t_world *world, t_uvec dir_view);

// hit.c
t_bool	hit(t_list *objs, const t_ray *r, t_intvl t, t_hit *rec);
t_bool	hit_plane(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec);
t_bool	hit_sphere(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec);
// t_bool	hit_cylinder(const t_obj *obj, const t_ray *r, t_intvl t, t_hit *rec);

// texture.c
t_txtr	texture(t_name name, t_color first, t_color second, t_scl scale);

// utill.c
t_uvec	direction(t_point from, t_point at);
t_scl	degrees_to_radians(t_scl degrees);

#endif