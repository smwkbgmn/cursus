/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:55:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/11 02:06:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	op_swap(char *line, t_stack *a, t_stack *b);
static t_bool	op_push(char *line, t_stack **a, t_stack **b);
static t_bool	op_rotate(char *line, t_stack **a, t_stack **b);

t_bool	execute(char *line, t_stack **a, t_stack **b)
{
	return (op_swap(line, *a, *b)
		|| op_push(line, a, b)
		|| op_rotate(line, a, b));
}

static t_bool	op_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	op_push(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(b, a);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	op_rotate(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		set_rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		set_rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		set_rotate(a);
		set_rotate(b);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		set_rotate_rvs(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		set_rotate_rvs(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		set_rotate_rvs(a);
		set_rotate_rvs(b);
	}
	else
		return (FALSE);
	return (TRUE);
}
