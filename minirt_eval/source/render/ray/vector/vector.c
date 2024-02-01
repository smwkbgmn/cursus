/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:37:31 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/31 23:01:19 by donghyu2         ###   ########.fr       */
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

t_vec	unit(t_vec vec)
{
	return (dv(vec, length(vec)));
}

t_scl	length(t_vec vec)
{
	return (sqrt(square(vec)));
}

t_scl	square(t_vec vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
