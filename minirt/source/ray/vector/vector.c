/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:37:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 13:07:54 by donghyu2         ###   ########.fr       */
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

// Return true if the vector is close to zero in all dimensions
t_bool	near_zero(t_vec vec)
{
	t_scl	s = 1e-8;
	return (abs(vec.x < s) && abs(vec.y < s) && abs(vec.z < s));
	// return (fabs(vec.x < s) && fabs(vec.y < s) && fabs(vec.z < s));
}

t_vec	reflect(t_vec vec, t_vec n)
{
	return (sb(vec, mt(n, 2 * dot(vec, n))));
}
