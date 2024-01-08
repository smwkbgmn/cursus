/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:32:54 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/08 14:58:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# include "libft.h"
# include "utill.h"
# include "error.h"

# define LOOP 1

// vector.c
t_vec	vec(t_scl x, t_scl y, t_scl z);
void	set(t_vec *vec, t_scl x, t_scl y, t_scl z);
t_scl	square(t_vec vec);
t_scl	length(t_vec vec);
t_vec	unit(t_vec vec);
t_vec	randv(void);
t_vec	randv_range(t_scl min, t_scl max);
t_bool	near_zero(t_vec vec);

// for DIFFUSE
t_vec	randv_on_hemisphere(t_uvec normal);
t_uvec	randuv(void);
t_vec	reflect(t_vec vec, t_vec n);
t_vec	refract(const t_uvec *unit, const t_vec *n, t_scl etai_over_etat);

// operation.c
t_vec	ad(t_vec v1, t_vec v2);
t_vec	sb(t_vec v1, t_vec v2);
// t_vec	multi(t_vec v1, t_vec v2);
t_vec	mt(t_vec vec, t_scl t);
t_vec	mtv(t_vec v1, t_vec v2);
t_vec	dv(t_vec vec, t_scl t);

// product.c
t_scl	dot(t_vec v1, t_vec v2);
t_vec	cross(t_vec v1, t_vec v2);

#endif