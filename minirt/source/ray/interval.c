/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:51:51 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 07:15:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_intvl	interval(t_scl min, t_scl max)
{
	t_intvl	intvl;

	intvl.min = min;
	intvl.max = max;
	return (intvl);
}

// t_intvl	interval(void)
// {
// 	t_intvl	intvl;

// 	intvl.min = INFINITY;
// 	intvl.max = INFINITY * -1;
// 	// intvl.min = INFINITY;
// 	// intvl.max = INFINITY * -1;
// 	return intvl;
// }

// t_intvl	interval_set(t_scl min, t_scl max)
// {
// 	t_intvl	intvl;

// 	intvl.min = min;
// 	intvl.max = max;
// 	return (intvl);
// }

// t_intvl	interval(t_scl min, t_scl max)
// {
// 	t_intvl	intvl;

// 	intvl.min = min;
// 	intvl.max = max;
// 	return (intvl);
// }

t_bool	contains(t_scl x, t_intvl intvl)
{
	return (intvl.min <= x && x <= intvl.max);
}

t_bool	surrounds(t_scl x, t_intvl intvl)
{
	return (intvl.min < x && x < intvl.max);
}

t_scl	clamp(t_scl x, t_intvl intvl)
{
	if (x < intvl.min)
		return (intvl.min);
	if (x > intvl.max)
		return (intvl.max);
	return x;
}