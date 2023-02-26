/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/27 07:10:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. check input char* valid
// 2. init the stack a
// 3. check existence of duplication with stack a

#include "push_swap.h"

void	init_que(t_que *a, t_que *b, int ac);
void	envalue_que(char **av, t_que *a);

void	print_ary(t_que a);

int	main(int ac, char **av)
{
	t_que	a;
	t_que	b;

	if (ac < 2)
		return (0);
	init_que(&a, &b, ac);
	envalue_que(++av, &a);

	print_ary(a);
	sa(&a);
	print_ary(a);

	return (0);
}

void	print_ary(t_que a)
{
	t_uint	i;

	for (i = 0; i < a.size; i++)
		printf("%d\n", a.ary[i]);
}

void	init_que(t_que *a, t_que *b, int ac)
{
	t_uint	cnt;

	cnt = ac - 1;
	a->ary = ft_calloc(cnt, sizeof(int));
	a->size = cnt;
	a->top = 0;
	a->btm = 0;
	b->ary = ft_calloc(cnt, sizeof(int));
	b->size = cnt;
	b->top = 0;
	b->btm = 0;
}

void	envalue_que(char **av, t_que *a)
{
	t_uint	idx;

	idx = 0;
	while (idx < a->size)
	{
		a->ary[idx++] = ft_atoi(*(av++));
		a->btm++;
	}
}

int	*ptr(t_que *ptr, t_uint idx)
{
	return (&ptr->ary[idx % ptr->size]);
}
