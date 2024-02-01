/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:32:54 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 17:19:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>

# include "struct.h"

// vector.c
t_vec	vec(t_scl x, t_scl y, t_scl z);
t_vec	unit(t_vec vec);
t_scl	length(t_vec vec);
t_scl	square(t_vec vec);

// operation.c
t_vec	ad(t_vec v1, t_vec v2);
t_vec	sb(t_vec v1, t_vec v2);
t_vec	mt(t_vec vec, t_scl t);
t_vec	mtv(t_vec v1, t_vec v2);
t_vec	dv(t_vec vec, t_scl t);

// product.c
t_scl	dot(t_vec v1, t_vec v2);
t_vec	cross(t_vec v1, t_vec v2);

#endif