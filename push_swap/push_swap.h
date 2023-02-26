/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/27 07:06:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft.h"

typedef short			t_bool;
typedef unsigned int	t_uint;

typedef struct s_que
{
	int		*ary;
	t_uint	size;
	t_uint	top;
	t_uint	btm;
}	t_que;

int		*ptr(t_que *ptr, t_uint idx);

void	sa(t_que *a);
void	sb(t_que *b);
void	ss(t_que *a, t_que *b);

#endif