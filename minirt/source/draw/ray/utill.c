/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:21:44 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 09:09:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// t_scl	num_infinity(void)
// {
// 	return (INFINITY);
// }

// t_scl	num_pi(void)
// {
// 	return (3.1415926535897932385);
// }

t_scl	degrees_to_radians(t_scl degrees)
{
	return (degrees * PI / 180.0);
	// return (degrees * num_pi() / 180.0);
}

t_scl	randn(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

t_scl	randn_range(t_scl min, t_scl max)
{
	return (min + (max - min) * randn());
}
