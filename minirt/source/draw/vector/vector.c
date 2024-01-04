/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:37:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 10:07:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"

t_vec	vec(t_scl x, t_scl y, t_scl z)
{
	t_vec	vec;
	
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

void	set(t_vec *vec, t_scl x, t_scl y, t_scl z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_scl	square(t_vec vec)
{
	return (pow(vec.x , 2) +
		pow(vec.y , 2) +
		pow(vec.z , 2));
}

t_scl	length(t_vec vec)
{
	return (sqrt(square(vec)));
}

t_vec	unit(t_vec vec)
{
	return (dv(vec, length(vec)));
}

t_vec	randv(void)
{
	return (vec(randn(), randn(), randn()));
}

t_vec	randv_range(t_scl min, t_scl max)
{
	return (vec(randn_range(min, max), randn_range(min, max), randn_range(min, max)));
}

// for DIFFUESE
static t_vec	randv_in_unit_sphere(void);

t_vec	randv_on_hemisphere(t_uvec normal)
{
	t_uvec	on_unit_sphere = randuv();

	// In the same hemisphere as the normal
	if (dot(on_unit_sphere, normal) > 0.0)
		return (on_unit_sphere);
	else
		return (mt(on_unit_sphere, -1));
}

t_uvec	randuv(void)
{
	return unit(randv_in_unit_sphere());
}

static t_vec	randv_in_unit_sphere(void)
{
	t_vec	p;

	while (LOOP)
	{
		p = randv_range(-1, 1);
		if (square(p) < 1)
			break ;
	}
	return (p);
}

