/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:35:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/29 20:04:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libft.h"
# include "vector.h"

# define CLR_SCALE 255

// ray.c
t_ray	ray(t_crd org, t_vec direc);
t_crd	ray_at(t_ray *ray, t_scl t);
t_color	ray_color(t_ray *ray);

// hit.c
t_bool	hit_sphere(const t_crd center, t_scl radius, const t_ray r);

#endif