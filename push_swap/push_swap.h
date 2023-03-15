/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:11:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "../1_archive/libft/include/libft.h"
# include "libft.h"

typedef short			t_bool;
typedef unsigned int	t_uint;

void	sa(t_list *head_a);
void	sb(t_list *head_b);
void	ss(t_list *head_a, t_list *head_b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

////////////// for test ///////////

# include <stdio.h>

void	test_print_input(char **av);
void	test_print_stack(t_list *head);

///////////////////////////////////

#endif