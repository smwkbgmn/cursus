/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/03 21:03:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ref(t_stack *stk, int idx_to_move);
// int	get_run_size(t_stack *a);

// -- sort with rotating stack a ---
void	push_run_ascend(t_stack **a, t_stack **b, t_uint size);
void	push_run_descend(t_stack **a, t_stack **b, t_uint size);
int		find_max(t_stack *run);
int		find_min(t_stack *run);
int		find_position_max(t_stack *run, t_uint idx, t_uint size);
int		find_position_min(t_stack *run, t_uint idx, t_uint size);
t_stack	*init_run(t_stack *a, t_uint *size);

// -- sort with rotating stack b ---
// void	push_mini_run(t_stack **a, t_stack **b, t_uint size);
// void	search_push(t_stack **a, t_stack **b, t_uint cnt);
// t_uint	search(t_stack *b, int data);

void	sort(t_stack **a, t_stack **b)
{
	t_uint	size;

	// size = get_run_size(*a);
	size = 8;
	push_run_ascend(a, b, size);
	push_run_descend(a, b, size);
}


// ------------------------------
// | sort with rotating stack a |
// ------------------------------


void	push_run_ascend(t_stack **a, t_stack **b, t_uint size)
{
	t_stack	*run;
	t_uint	idx;
	int		idx_to_move;

	run = init_run(*a, &size);
	// test_print_stack(run, NULL);

	idx = 0;
	while (run)
	{
		idx_to_move = find_position_max(run, idx, size);
		// printf("size : %d, idx : %d, idx_to_move : %d\n", size, idx, idx_to_move);
		if (idx_to_move > 0)
		{
			while (idx_to_move-- > 0)
			{
				ra(a);
				set_rotate(&run);
				idx++;
			}
		}
		else
		{
			while (idx_to_move++ < 0)
			{
				rra(a);
				set_rotate_rvs(&run);
				idx--;
			}
		}
		pb(a, b);
		del_node(&run);
		size--;
		// test_print_stack(*a, run);
	}
}

void	push_run_descend(t_stack **a, t_stack **b, t_uint size)
{
	t_stack	*run;
	t_uint	idx;
	int		idx_to_move;

	run = init_run(*a, &size);
	test_print_stack(run, NULL);

	idx = 0;
	while (run)
	{
		idx_to_move = find_position_min(run, idx, size);
		printf("size : %d, idx : %d, idx_to_move : %d\n", size, idx, idx_to_move);
		if (idx_to_move > 0)
		{
			while (idx_to_move-- > 0)
			{
				ra(a);
				set_rotate(&run);
				idx++;
			}
		}
		else
		{
			while (idx_to_move++ < 0)
			{
				rra(a);
				set_rotate_rvs(&run);
				idx--;
			}
		}
		pb(a, b);
		del_node(&run);
		size--;
		test_print_stack(*a, run);
	}
}

int	find_max(t_stack *run)
{
	int	max;

	max = run->data;
	run = run->next;
	while (run)
	{
		if (max < run->data)
			max = run->data;
		run = run->next;
	}
	return (max);
}

int	find_min(t_stack *run)
{
	int	min;

	min = run->data;
	run = run->next;
	while (run)
	{
		if (min > run->data)
			min = run->data;
		run = run->next;
	}
	return (min);
}

int	find_position_max(t_stack *run, t_uint idx, t_uint size)
{
	int	idx_to_move;
	int	max;

	idx_to_move = 0;
	max = find_max(run);
	while (run)
	{
		if (run->data == max)
		{
			if (idx + idx_to_move < size)
				return (idx_to_move);
			else
				return (idx_to_move - size);
		}
		else
		{
			idx_to_move++;
			run = run->next;
		}
	}
	return (0);
}

int	find_position_min(t_stack *run, t_uint idx, t_uint size)
{
	int	idx_to_move;
	int	min;

	idx_to_move = 0;
	min = find_min(run);
	while (run)
	{
		if (run->data == min)
		{
			if (idx + idx_to_move < size)
				return (idx_to_move);
			else
				return (idx_to_move - size);
		}
		else
		{
			idx_to_move++;
			run = run->next;
		}
	}
	return (0);
}

t_stack	*init_run(t_stack *a, t_uint *size)
{
	t_stack	*run;
	t_uint	idx;

	run = NULL;
	idx = 0;
	while (a && idx++ < *size)
	{
		ft_stkadd_back(&run, ft_stknew(ref(a, 0)));
		a = a->next;
	}
	*size = idx - 1;
	return (run);
}

// ------------------------------
// | sort with rotating stack b |
// ------------------------------

// void	push_mini_run(t_stack **a, t_stack **b, t_uint size)
// {
// 	t_uint	cnt;

// 	if (ref(*a, 0) < ref (*a, 1))
// 		sa(*a);
// 	pb(a, b);
// 	pb(a, b);

// 	test_print_stack(*a, *b);

// 	cnt = 2;
// 	while (*a && cnt < size)
// 	{
// 		search_push(a, b, cnt++);
// 		test_print_stack(*a, *b);
// 	}
// }

// void	search_push(t_stack **a, t_stack **b, t_uint cnt)
// {
// 	t_uint	idx;

// 	idx = search(*b, ref(*a, 0));
// 	printf("idx for search --- [%d]\n", idx);
// 	if (idx < cnt / 2)
// 	{
// 		while (idx-- > 0)
// 			rb(b);
// 	}
// 	else
// 	{
// 		idx = cnt - idx;
// 		while (idx-- > 0)
// 			rrb(b);
// 	}
// 	pb(a, b);
// }

// t_uint	search(t_stack *b, int data)
// {
// 	t_uint	idx;
// 	t_stack	*prev;

// 	idx = 0;
// 	prev = ft_stklast(b);
// 	while (b)
// 	{
// 		if (ref(b, 0) < data && (prev == NULL || ref(prev, 0) < data))
// 			return (idx);
// 		prev = b;
// 		b = b->next;
// 		idx++;
// 	}
// 	return (idx);
// }

// t_bool	is_sorted(t_stack *b)
// {
	
// }

int	ref(t_stack *stk, int idx_to_move)
{
	return (ft_stkidx(stk, idx_to_move)->data);
}

// int	get_run_size(t_stack *a)
// {
// 	t_uint	size_stk;
// 	t_uint	size_run;

// 	size_stk = ft_stksize(a);
// 	size_run = 0;
// 	while (size_stk <= 64)
// 	{
// 		size_run++;
// 		size_stk /= 2;
// 	}
// 	return (size_run);
// }
