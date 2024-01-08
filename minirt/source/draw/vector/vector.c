/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:37:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/06 13:33:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Return true if the vector is close to zero in all dimensions
t_bool	near_zero(t_vec vec)
{
	t_scl	s = 1e-8;
	return (abs(vec.x < s) && abs(vec.y < s) && abs(vec.z < s));
	// return (fabs(vec.x < s) && fabs(vec.y < s) && fabs(vec.z < s));
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

t_vec	reflect(t_vec vec, t_vec n)
{
	return (sb(vec, mt(n, 2 * dot(vec, n))));
}

t_vec	refract(const t_uvec *unit, const t_vec *n, t_scl etai_over_etat)
{
	t_scl	cos_theta = fmin(dot(mt(*unit, -1), *n), 1.0);
	t_vec	r_out_perp = mt(ad(*unit, mt(*n, cos_theta)), etai_over_etat);
	t_vec	r_out_parallel = mt(*n, -sqrt(fabs(1.0 - square(r_out_perp))));
	return (ad(r_out_perp, r_out_parallel));
}
