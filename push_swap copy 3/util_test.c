/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:53:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/05 20:31:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

t_bool	is_there_same(int *ary, int size, int n);

void	gen_input(int size)
{
	FILE	*fp;
	int		*ary;
	int		idx;
	int		n_rand;

	if (size > 0)
	{
		fp = fopen("in", "w");
		ary = malloc(sizeof(int) * size);
		idx = 0;
		while (idx < size)
		{
			ary[idx] = -1;
			n_rand = rand() % size;
			if (!is_there_same(ary, size, n_rand))
			{
				ary[idx] = n_rand;
				if (idx + 1 != size)
					fprintf(fp, "%d ", ary[idx]);
				else
					fprintf(fp, "%d", ary[idx]);
				idx++;
			}
		}
		fclose(fp);
	}
}

t_bool	is_there_same(int *ary, int size, int n)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (ary[idx] == n)
			return (TRUE);
		else if (ary[idx] == -1)
			break ;
		else
			idx++;
	}
	return (FALSE);
}

void	test_print_input(char **av)
{
	printf("\n[[input]]\n");
	while (*av)
	{
		printf("%s", *(av++));
		if (*av)
			printf(" ");
	}
	printf("\n");
}

void	test_print_stack(t_stack *a, t_stack *b)
{
	printf("\n");
	printf("a            b\n");
	printf("-            -\n");
	while (a || b)
	{
		if (a)
		{
			printf("%-13d", a->data);
			a = a->next;
		}
		else
			printf("             ");
		if (b)
		{
			printf("%-13d", b->data);
			b = b->next;
		}
		printf("\n");
	}
	printf("\n");
}

void	test_sample_implement(t_stack **a, t_stack **b)
{
	sa(*a);
	test_print_stack(*a, *b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	test_print_stack(*a, *b);
	ra(a);
	rb(b);
	test_print_stack(*a, *b);
	rra(a);
	rrb(b);
	test_print_stack(*a, *b);
	sa(*a);
	test_print_stack(*a, *b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
	test_print_stack(*a, *b);
}
