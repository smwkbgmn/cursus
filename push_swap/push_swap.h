/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/23 18:26:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

typedef short			t_bool;
typedef unsigned int	t_uint;

void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sort(t_list **a, t_list **b);

////////////// for test ///////////

# include <stdio.h>

void	test_print_input(char **av);
void	test_print_stack(t_list *a, t_list *b);
void	test_sample_implement(t_list **a, t_list **b);

///////////////////////////////////

#endif