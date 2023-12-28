/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:14:24 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 09:11:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "vector.h"

t_vec	vad(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x + v2.x;
	rst.y = v1.y + v2.y;
	rst.z = v1.z + v2.z;
	return (rst);
}

t_vec	vsb(t_vec v1, t_vec v2)
{
	t_vec	rst;

	rst.x = v1.x - v2.x;
	rst.y = v1.y - v2.y;
	rst.z = v1.z - v2.z;
	return (rst);
}

// t_vec	vmulti(t_vec v1, t_vec v2)
// {
// 	t_vec	rst;

// 	rst.x = v1.x * v2.x;
// 	rst.y = v1.y * v2.y;
// 	rst.z = v1.z * v2.z;
// }

t_vec	vmt(t_vec vec, t_scl t)
{
	t_vec	rst;

	rst.x = vec.x * t;
	rst.y = vec.y * t;
	rst.z = vec.z * t;
	return (rst);
}

t_vec	vdv(t_vec vec, t_scl t)
{
	t_vec	rst;

	if (t)
	{
		rst.x = vec.x / t;
		rst.y = vec.y / t;
		rst.z = vec.z / t;
		return (rst);
	}
	printf("YOU'RE ATTEMPTING TO DIVIDE BY ZERO\n");
	return (vec);
}
