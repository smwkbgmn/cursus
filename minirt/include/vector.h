/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:32:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/12/28 09:10:12 by donghyu2         ###   ########.fr       */
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
t_vec	vad(t_vec v1, t_vec v2);
t_vec	vsb(t_vec v1, t_vec v2);
// t_vec	vmulti(t_vec v1, t_vec v2);
t_vec	vmt(t_vec vec, t_scl t);
t_vec	vdv(t_vec vec, t_scl t);

// product.c
t_scl	vdot(t_vec v1, t_vec v2);
t_vec	vcorss(t_vec v1, t_vec v2);

#endif