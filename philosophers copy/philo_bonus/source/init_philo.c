/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:08:35 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 03:49:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "philo.h"

static t_process	*new_philo(t_uint idx);
static t_list		*ft_lstnew(t_process *philo_new, t_vars *share);
static void			ft_lstadd(t_list **list, t_list *new);

void	init_philosophers(t_list **data, t_vars *share)
{
	t_list		*new;
	t_uint		idx;

	idx = 0;
	while (idx < share->config.cnt_philo)
	{
		new = ft_lstnew(new_philo(idx), share);
		ft_lstadd(data, new);
		idx++;
	}
}

static t_process	*new_philo(t_uint idx)
{
	t_process	*philo;

	philo = errext(malloc(sizeof(t_process)));
	memset(philo, 0, sizeof(t_process));
	philo->info.name = idx + 1;
	philo->info.stat = STARVE;
	// philo->info.key[0] = init_sem("stat", 1);
	// philo->info.key[1] = init_sem("timer", 1);
	return (philo);
}

static t_list	*ft_lstnew(t_process *philo_new, t_vars *share)
{
	t_list	*list_new;

	list_new = errext(malloc(sizeof(t_list)));
	list_new->philo = philo_new;
	list_new->share = share;
	list_new->next = list_new;
	list_new->prev = list_new;
	return (list_new);
}

static void	ft_lstadd(t_list **data, t_list *new)
{
	t_list	*head;
	t_list	*tail;

	if (*data)
	{
		head = *data;
		tail = (*data)->prev;
		tail->next = new;
		new->next = head;
		new->prev = tail;
		head->prev = new;
	}
	else
		*data = new;
}
