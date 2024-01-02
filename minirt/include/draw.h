/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:00:17 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 07:37:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

// # include <stdio.h>

# include "scene.h"
# include "ray.h"

/* draw.c */
void	write_color(t_color color);

/* sphere.c */
void	sphere(t_point center, t_scl radius);

#endif