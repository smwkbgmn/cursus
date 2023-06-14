/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:54:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/14 21:18:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

t_bool			execute(char *line, t_stack **a, t_stack **b);
static t_bool	parse_stdin(t_stack **a, t_stack **b);
static void		write_call(t_stack *a, t_stack *b);
static t_bool	check_disorder(t_stack *a);

int	main(int ac, char **av)
{
	char			**input;
	static t_stack	*a;
	static t_stack	*b;

	if (ac > 1)
	{
		input = av + 1;
		if (check_valid(ac, input) && init_stack(&a, ac, input))
		{
			if (check_duplication(a) && ft_stksize(a) > 1)
			{
				if (parse_stdin(&a, &b))
					write_call(a, b);
				else
					write_error();
			}
			ft_stkclear(a);
			ft_stkclear(b);
		}
	}
	return (0);
}

static t_bool	parse_stdin(t_stack **a, t_stack **b)
{
	char			*line;
	static t_bool	valid;

	line = get_next_line(STDIN);
	if (line)
	{
		if (execute(line, a, b))
			valid = parse_stdin(a, b);
		else
			valid = FALSE;
		free(line);
	}
	else
		valid = TRUE;
	return (valid);
}

static void	write_call(t_stack *a, t_stack *b)
{
	if (a && !b && check_disorder(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static t_bool	check_disorder(t_stack *a)
{
	if (ref(a) == 0)
	{
		while (ref(a) < ref(a->next))
			a = a->next;
		if (ref(a->next) == 0)
			return (TRUE);
	}
	return (FALSE);
}
