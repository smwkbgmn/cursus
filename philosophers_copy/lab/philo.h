/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/19 18:37:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define ERROR -1

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_stat
{
	EATING,
	SLEEPING,
	THINK,
	STARVE,
	FORK,
	DEAD
}	t_stat;

typedef struct timeval		t_timeval;
typedef unsigned long long	t_msec;
typedef unsigned int		t_uint;
typedef pthread_mutex_t		t_mutex;

typedef struct s_time
{
	t_msec	start;
	t_msec	curnt;
}	t_time;

typedef struct s_config
{
	t_uint	cnt_philo;
	t_msec	delay_die;
	t_msec	delay_eat;
	t_msec	delay_sleep;
	int		cnt_eat;
}	t_config;

typedef struct s_data
{
	t_config	config;
	t_time		time_sys;
	t_mutex		lock_print;
}	t_data;

typedef struct s_philo
{
	t_uint	name;
	t_stat	stat;
	t_bool	fork;
	t_uint	eating;
	t_time	timer_death;
	t_mutex	lock_stat;
	t_mutex	lock_fork;
}	t_philo;

typedef struct s_thread
{
	pthread_t	id;
	pthread_t	id_monitor;
	t_philo		philo;
	t_data		*data;
}	t_thread;

typedef struct s_list
{
	t_thread		*thread;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_bool	validate_input(char **av);
void	init_data(int ac, char **av, t_data *data);
void	init_philosophers(t_list **philos, t_data *data);

void	start_life(t_list *philos, t_data *data);

void	print_status(t_thread *philo, t_stat stat);

t_list	*ft_lstnew(t_thread *philo_new);
void	ft_lstadd(t_list **philos, t_list *new);

t_uint	ft_strlen(char *str);
t_uint	ft_atoi(char *av);

void	suspend(t_msec ms);
void	set_time(t_msec *timeval);
t_msec	get_time_elapsed(t_time *time);
// void	set_time(t_timeval *timeval);
// t_msec	get_time_elapsed(t_time *time);

void	*life(void *arg);
void	set_status(t_thread *philo, t_stat stat_to_change);
t_stat	ref_status(t_thread *philo);
void	set_fork(t_thread *philo, t_bool bool_to_change);
t_bool	ref_fork(t_thread *philo);

void	start_monitor(t_list *philos);
void	*monitor(void *arg);

// void	philo_eat(t_thread *curnt, t_thread *next);
t_bool	philo_eat(t_thread *curnt, t_thread *next);
void	philo_sleep(t_thread *curnt);
t_bool	is_fork_available(t_thread *curnt, t_thread *next);

/* DEBUG */

# include <stdio.h>

#endif