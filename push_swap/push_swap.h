/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 01:45:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef short			t_bool;
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
t_uint	get_cnt_disorder(t_stack *a);

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
void	sort_hourglass(t_stack **a, t_stack **b);

t_stack	*ft_stknew(int data);
void	ft_stkadd_back(t_stack **stack, t_stack *new);
t_uint	ft_stksize(t_stack *stack);
void	ft_stkclear(t_stack *stk);
t_uint	ref(t_stack *stk);

////////////// for test ///////////

# include <stdio.h>

void	test_print_input(char **av);
void	test_print_stack(t_stack *a, t_stack *b);
void	test_sample_implement(t_stack **a, t_stack **b);

///////////////////////////////////

#endif