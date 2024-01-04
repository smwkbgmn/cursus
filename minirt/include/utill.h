/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:39:16 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/04 12:05:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILL_H
# define UTILL_H

# include "struct.h"

// utill.c
// t_scl	num_infinity(void);
// t_scl	num_pi(void);
t_scl	degrees_to_radians(t_scl degrees);
t_scl	randn(void);
t_scl	randn_range(t_scl min, t_scl max);

#endif