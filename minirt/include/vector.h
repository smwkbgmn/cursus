/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:32:54 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/02 11:50:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# include "struct.h"
# include "error.h"

/* vector.c */
t_vec	vec(t_scl x, t_scl y, t_scl z);
void	set(t_vec *vec, t_scl x, t_scl y, t_scl z);
t_scl	square(t_vec vec);
t_scl	length(t_vec vec);
t_vec	unit(t_vec vec);
// t_vec	min(t_vec v1, t_vec v2);

/* operation.c */
t_vec	ad(t_vec v1, t_vec v2);
t_vec	sb(t_vec v1, t_vec v2);
// t_vec	multi(t_vec v1, t_vec v2);
t_vec	mt(t_vec vec, t_scl t);
t_vec	dv(t_vec vec, t_scl t);

/* product.c */
t_scl	dot(t_vec v1, t_vec v2);
t_vec	corss(t_vec v1, t_vec v2);

#endif