/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:01:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/11 15:02:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

static t_bool	init_keys_philo(t_list *data, t_uint cnt);
static t_thread	*new_philo(t_uint idx);
static t_list	*ft_lstnew(t_thread *thread_new, t_vars *prgm);
static void		ft_lstadd(t_list **list, t_list *new);

t_bool	init_philosophers(t_list **data, t_vars *prgm)
{
	t_uint		idx;
	t_list		*list_new;
	t_thread	*thread;

	idx = 0;
	while (idx < prgm->config.cnt_philo)
	{
		thread = new_philo(idx);
		if (thread)
		{
			list_new = ft_lstnew(thread, prgm);
			if (list_new)
			{
				ft_lstadd(data, list_new);
				idx++;
				continue ;
			}
			else
				free(thread);
		}
		ft_lstadd(data, NULL);
		break ;
	}
	return (idx == prgm->config.cnt_philo
		&& init_keys_philo(*data, prgm->config.cnt_philo));
}

static t_bool	init_keys_philo(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx < cnt && init_keys(&data->thread->philo.key[0]))
	{
		data = data->next;
		idx++;
	}
	return (idx == cnt);
}

static t_thread	*new_philo(t_uint idx)
{
	t_thread	*thread;

	thread = malloc(sizeof(t_thread));
	if (thread)
	{
		thread->id = 0;
		thread->id_monitor = 0;
		thread->philo.name = idx + 1;
		thread->philo.stat = STARVE;
		thread->philo.eating = 0;
	}
	return (thread);
}

static t_list	*ft_lstnew(t_thread *thread_new, t_vars *prgm)
{
	t_list	*list_new;

	list_new = malloc(sizeof(t_list));
	if (list_new)
	{
		list_new->thread = thread_new;
		list_new->program = prgm;
		list_new->next = list_new;
		list_new->prev = list_new;
	}
	return (list_new);
}

static void	ft_lstadd(t_list **list, t_list *new)
{
	t_list	*head;
	t_list	*tail;

	if (*list)
	{
		head = *list;
		tail = (*list)->prev;
		tail->next = new;
		new->next = head;
		head->prev = new;
		new->prev = tail;
	}
	else
		*list = new;
}
