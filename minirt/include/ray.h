/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:35:59 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 11:51:54 by donghyu2         ###   ########.fr       */
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
t_point	ray_at(const t_ray *ray, t_scl t);
t_color	ray_color(const t_ray *r, t_list *objs);

/* hit.c */
t_bool	hit(t_list *objs, const t_ray *r, t_scl t[2], t_hit *hit);

/* utill.c*/
// t_scl	num_infinity(void);
// t_scl	num_pi(void);
t_scl	degrees_to_radians(t_scl degrees);

#endif