/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:51:51 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 14:40:47 by donghyu2         ###   ########.fr       */
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

t_bool	contains(t_scl x, t_intvl intvl)
{
	return (intvl.min <= x && x <= intvl.max);
}

t_bool	surrounds(t_scl x, t_intvl intvl)
{
	return (intvl.min < x && x < intvl.max);
}
