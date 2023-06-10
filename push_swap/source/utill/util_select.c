/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:33:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/10 22:21:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	reverse(t_stack *a, t_uint size);
static t_bool	wrong_position(t_stack *a, t_uint size);
static t_bool	reverse_wrong_position(t_stack *a, t_uint size);

t_sort	select_algorithm(t_stack *a)
{
	t_uint	size;
	t_uint	cnt;

	size = ft_stksize(a);
	cnt = get_cnt_disorder(a, size);
	if ((cnt == 0 && ref(a) == 0))
		return (NULL);
	else if (size <= 3)
		return (&sort_3);
	else if (size <= 5)
		return (&sort_5);
	else if (reverse(a, size) || reverse_wrong_position(a, size))
		return (&sort_reverse);
	else if (wrong_position(a, size))
		return (&sort_rotate);
	else if (cnt < 16)
		return (&sort_insertion);
	else
		return (&sort_hourglass);
}

t_uint	get_cnt_disorder(t_stack *a, t_uint size)
{
	t_uint	cnt;
	t_uint	order;

	while (ref(a) != 0)
		a = a->next;
	cnt = 0;
	order = 0;
	while (order < size)
	{
		if (ref(a) != order)
			cnt++;
		order++;
		a = a->next;
	}
	return (cnt);
}

static t_bool	reverse(t_stack *a, t_uint size)
{
	while (size-- > 0 && ref(a) > ref(a->next))
		a = a->next;
	return (size == 0);
}

static t_bool	wrong_position(t_stack *a, t_uint size)
{
	t_uint	cnt;

	cnt = 0;
	while (size-- > 0)
	{
		if (ref(a) > ref(a->next))
			cnt++;
		if (cnt > 1)
			break ;
		else
			a = a->next;
	}
	return (cnt == 1);
}

static t_bool	reverse_wrong_position(t_stack *a, t_uint size)
{
	t_uint	cnt;

	cnt = 0;
	while (size-- > 0)
	{
		if (ref(a) < ref(a->next))
			cnt++;
		a = a->next;
	}
	return (cnt == 1);
}
