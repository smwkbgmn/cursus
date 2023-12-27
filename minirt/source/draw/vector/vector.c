/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:37:31 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:15:19 by donghyu2         ###   ########.fr       */
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

void	vset(t_vec *vec, t_scl x, t_scl y, t_scl z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_scl	vmgntd(t_vec vec)
{
	return (sqrt(pow(vec.x, 2)
		+ pow(vec.y, 2)
		+ pow(vec.z, 2)));
}

t_vec	vunit(t_vec vec)
{
	return (vdiv(vec, vmgntd(vec)));
}

t_vec	vmin(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = (v1.x * (v1.x <= v2.x)) + (v2.x * (v1.x > v2.x));
	rst.y = (v1.y * (v1.y <= v2.y)) + (v2.y * (v1.y > v2.y));
	rst.z = (v1.z * (v1.z <= v2.z)) + (v2.z * (v1.z > v2.z));
	return (rst);
}
