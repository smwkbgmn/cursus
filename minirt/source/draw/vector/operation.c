/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:14:24 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 03:32:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector.h"

t_vec	vadd(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x + v2.x;
	rst.y = v1.y + v2.y;
	rst.z = v1.z + v2.z;
	return (rst);
}

t_vec	vsub(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x - v2.x;
	rst.y = v1.y - v2.y;
	rst.z = v1.z - v2.z;
	return (rst);
}

t_vec	vdiv(t_vec vec, t_scl val)
{
	t_vec	rst;

	if (val)
	{
		rst.x = vec.x / val;
		rst.y = vec.y / val;
		rst.z = vec.z / val;
		return (rst);
	}
	else
	{
		printf("YOUR ATTEMPTING DIVIDE BY ZERO\n");
		return (vec);
	}
}

t_vec	vmulti(t_vec vec, t_scl val)
{
	t_vec	rst;

	rst.x = vec.x * val;
	rst.y = vec.y * val;
	rst.z = vec.z * val;
	return (rst);
}

// t_vec	vadd(t_vec *v1, t_vec *v2)
// {
// 	t_vec	rst;

// 	rst.x = v1->x + v2->x;
// 	rst.y = v1->y + v2->y;
// 	rst.z = v1->z + v2->z;
// 	return (rst);
// }

// t_vec	vsub(t_vec *v1, t_vec *v2)
// {
// 	t_vec	rst;

// 	rst.x = v1->x - v2->x;
// 	rst.y = v1->y - v2->y;
// 	rst.z = v1->z - v2->z;
// 	return (rst);
// }

// t_vec	div_scl(t_vec *vec, t_scl val)
// {
// 	t_vec	rst;

// 	if (val)
// 	{
// 		rst.x = vec->x / val;
// 		rst.y = vec->y / val;
// 		rst.z = vec->z / val;
// 		return (rst);
// 	}
// 	else
// 		return (*vec);
// }

// t_vec	multi_scl(t_vec *vec, t_scl val)
// {
// 	t_vec	rst;

// 	rst.x = vec->x * val;
// 	rst.y = vec->y * val;
// 	rst.z = vec->z * val;
// 	return (rst);
// }
