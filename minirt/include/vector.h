/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:32:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 05:14:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# include "struct.h"
# include "error.h"

// vector.c
t_vec	vec(t_scl x, t_scl y, t_scl z);
void	vset(t_vec *vec, t_scl x, t_scl y, t_scl z);
t_scl	vmgntd(t_vec vec);
t_vec	vunit(t_vec vec);
t_vec	vmin(t_vec v1, t_vec v2);

// operation.c
t_vec	vadd(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
t_vec	vdiv(t_vec vec, t_scl val);
t_vec	vmulti(t_vec vec, t_scl val);

// product.c
t_scl	vdot(t_vec v1, t_vec v2);
t_vec	vcorss(t_vec v1, t_vec v2);

#endif