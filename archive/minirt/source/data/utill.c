/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:56:53 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 01:45:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_color	albedo_rgb(t_color rgb, t_scl bright)
{
	return (mt(color(rgb.x / 255, rgb.y / 255, rgb.z / 255), bright));
}

t_uvec	valid_normal(t_uvec normal)
{
	if (!normal.x && !normal.y && !normal.z)
		err_usr("normalized vector must be set");
	return (normal);
}

t_scl	valid_size(t_scl value)
{
	if (!value)
		err_usr("the size of object couldn't be zero");
	return (value);
}
