/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:28:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/11 03:24:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "push_swap.h"

static t_bool	one_line(char *av);
static t_bool	count_digit(char *av);

t_bool	check_valid(int ac, char **av)
{
	while (ac-- > 1)
	{
		if (!one_line(*av))
			return (FALSE);
		else
			av++;
	}
	return (TRUE);
}

static t_bool	one_line(char *av)
{
	while (*av == ' ')
		av++;
	if (*av == '+' || *av == '-')
		av++;
	if (ft_isdigit(*av) && count_digit(av))
		return (TRUE);
	else
	{
		write_error();
		return (FALSE);
	}
}

static t_bool	count_digit(char *av)
{
	t_uint	cnt;

	cnt = 0;
	while (ft_isdigit(*av))
	{
		cnt++;
		av++;
	}
	return (cnt <= 10);
}

t_bool	check_duplication(t_stack *a)
{
	t_stack	*stk;
	t_uint	size;
	t_bool	*table;

	stk = a;
	size = ft_stksize(stk);
	table = ft_calloc(size, sizeof(t_uint));
	if (table)
	{
		while (size-- > 0)
		{
			if (table[stk->order] != FALSE)
			{
				write_error();
				break ;
			}
			table[stk->order] = TRUE;
			stk = stk->next;
		}
		free(table);
		if (stk == a)
			return (TRUE);
	}
	return (FALSE);
}

void	write_error(void)
{
	write(2, "Error\n", 6);
}
