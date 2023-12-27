/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:35:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:14:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "struct.h"

# define CLR_SCALE 255

// ray.c
t_ray	ray(t_crd org, t_vec wtf);
t_crd	ray_at(t_ray *ray, t_scl val);
t_ray	ray_primary(t_camera *cam, t_scl u, t_scl v);
t_color	ray_color(t_ray *ray);

#endif