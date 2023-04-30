/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:13:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/01 02:11:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_stack(char *av);
static void		init_order(t_stack *a);
static t_uint	get_order(t_stack *a, int num);

t_bool	init_stack(t_stack **a, int ac, char **av)
{
	t_stack	*stk_new;
	long	data;

	while (ac-- > 1)
	{
		while (**av == ' ')
			(*av)++;
		stk_new = get_stack(*av);
		if (!stk_new)
			return (FALSE);
		else
			ft_stkadd_back(a, stk_new);
		av++;
	}
	init_order(*a);
	return (TRUE);
}

static t_stack	*get_stack(char *av)
{		
	long	data;

	data = ft_atoi_long(av);
	if (data < INT_MIN || data > INT_MAX)
	{
		write_error();
		return (NULL);
	}
	else
		return (ft_stknew((int)data));
}

static void	init_order(t_stack *a)
{
	t_stack	*stk;

	stk = a;
	while (stk)
	{
		stk->order = get_order(stk, stk->data);
		stk = stk->next;
		if (stk == a)
			break ;
	}
}

static t_uint	get_order(t_stack *a, int num)
{
	t_stack	*stk;
	t_uint	order;

	stk = a;
	order = 0;
	while (stk)
	{
		if (stk->data < num)
			order++;
		stk = stk->next;
		if (stk == a)
			break ;
	}
	return (order);
}
