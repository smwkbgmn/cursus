/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/27 04:01:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. check input char* valid
// 2. init the stack a
// 3. check existence of duplication with stack a

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_que	a;
	t_que	b;
	t_uint	cnt;

	cnt = ac - 1;
	a.ary = ft_calloc(cnt, sizeof(int));
	a.size = cnt;
	a.head = 0;
	a.tail = 0;
	b.ary = ft_calloc(cnt, sizeof(int));
	b.size = cnt;
	b.head = 0;
	b.tail = 0;
	return (0);
}

t_uint	idx(t_que *ptr, int idx)
{
	if (idx < 0)
		return (ptr->size + idx);
	else
		return ((t_uint)idx);
}
