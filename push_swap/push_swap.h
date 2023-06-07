/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/07 12:36:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef unsigned int	t_uint;
typedef struct s_stack
{
	int				data;
	t_uint			order;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
typedef void			(*t_sort)(t_stack **, t_stack **);

void	write_error(void);

t_stack	*ft_stknew(int data);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
t_uint	ft_stksize(t_stack *stack);
void	ft_stkclear(t_stack *stk);
t_uint	ref(t_stack *stk);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_3(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sort_rotate(t_stack **a, t_stack **b);
void	sort_reverse(t_stack **a, t_stack **b);
void	sort_insertion(t_stack **a, t_stack **b);
void	sort_hourglass(t_stack **a, t_stack **b);

t_uint	find_start(t_stack *a);
t_uint	find_position_asc(t_stack *stk, t_uint size, t_uint order);
t_uint	find_position_dsc(t_stack *stk, t_uint size, t_uint order);
void	rotate_a_idx(t_stack **a, t_uint size, t_uint idx);
void	rotate_b_idx(t_stack **b, t_uint size, t_uint idx);

////////////// for test //////////////

# include <stdio.h>

void	test_print_input(char **av);
void	test_print_stack(t_stack *a, t_stack *b);
void	test_sample_implement(t_stack **a, t_stack **b);

//////////////////////////////////////

#endif