/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:34:37 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 22:26:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static t_scl	get_diffuse(t_uvec normal, t_uvec dir_light);
static t_scl	get_specular(t_uvec normal, t_uvec dir_light, t_uvec dir_view);

t_phong	phong(const t_hit *rec, const t_light *light, t_uvec dir_view)
{
	t_phong	phong;
	t_uvec	dir_light;

	dir_light = direction(rec->point, light->point);
	phong.diffuse = get_diffuse(rec->normal, dir_light);
	phong.specular = get_specular(rec->normal, dir_light, dir_view);
	phong.light = light->albedo;
	return (phong);
}

static t_scl	get_diffuse(t_uvec normal, t_uvec dir_light)
{
	return (fmax(dot(normal, dir_light), 0.0));
}

static t_scl	get_specular(t_uvec normal, t_uvec dir_light, t_uvec dir_view)
{
	t_uvec	dir_halfway;
	t_scl	theta_reflect_view;

	dir_halfway = unit(ad(dir_light, dir_view));
	theta_reflect_view = dot(normal, dir_halfway);
	return (pow(fmax(theta_reflect_view, 0.0), SPEC_SHINE));
}
