/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:14:24 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:11:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	ad(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x + v2.x;
	rst.y = v1.y + v2.y;
	rst.z = v1.z + v2.z;
	return (rst);
}

t_vec	sb(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x - v2.x;
	rst.y = v1.y - v2.y;
	rst.z = v1.z - v2.z;
	return (rst);
}

t_vec	mt(t_vec vec, t_scl t)
{
	t_vec	rst;

	rst.x = vec.x * t;
	rst.y = vec.y * t;
	rst.z = vec.z * t;
	return (rst);
}

t_vec	mtv(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x * v2.x;
	rst.y = v1.y * v2.y;
	rst.z = v1.z * v2.z;
	return (rst);
}

t_vec	dv(t_vec vec, t_scl t)
{
	t_vec	rst;

	if (t)
	{
		rst.x = vec.x / t;
		rst.y = vec.y / t;
		rst.z = vec.z / t;
		return (rst);
	}
	return (vec);
}
