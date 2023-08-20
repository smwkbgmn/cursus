/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 21:31:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define LOOP 1
# define ERROR -1

typedef struct timeval		t_timeval;
typedef unsigned long long	t_msec;
typedef unsigned int		t_uint;
typedef pthread_mutex_t		t_mutex;

typedef enum e_bool			t_bool;
typedef enum e_stat			t_stat;

typedef struct s_list		t_list;
typedef struct s_thread		t_thread;
typedef struct s_philo		t_philo;
typedef struct s_data		t_data;
typedef struct s_config		t_config;
typedef struct s_time		t_time;

typedef void				(*t_func)(t_list *);

/* INIT */
t_bool	validate_input(char **av);
void	init_data(int ac, char **av, t_data *data);
void	init_philosophers(t_list **list, t_data *data);

/* MAIN */
void	start_life(t_list *list, t_data *data);

/* UTILL */
void	print_status(t_thread *thread, t_stat stat);

t_list	*ft_lstnew(t_thread *philo_new);
void	ft_lstadd(t_list **list, t_list *new);

t_uint	ft_strlen(char *str);
t_uint	ft_atoi(char *av);

void	suspend(t_msec ms);
void	set_time(t_msec *time_ms);
t_msec	get_time_elapsed(t_time *time);

void	mtx_lock(t_mutex *key);
void	mtx_unlock(t_mutex *key);
void	mtx_init(t_mutex *key);
void	mtx_free(t_mutex *key);

t_bool	config_can_not_continue(t_thread *thread);
t_bool	philos_dead_while_mtx_wait(t_list *list);
void	set_status(t_thread *thread, t_stat stat_to_change);
t_stat	ref_status(t_thread *thread);
t_bool	ref_fork(t_thread *thread);

/* THREAD */
void	*life(void *arg);
void	philo_think(t_list *list);
void	philo_eat(t_list *list);
void	philo_sleep(t_list *list);
void	philo_do(t_thread *thread, t_stat status);

void	*monitor(void *arg);

enum e_bool
{
	FALSE,
	TRUE
};

enum e_stat
{
	THINK,
	EAT,
	SLEEP,
	DEAD
};

struct s_time
{
	t_msec	start;
	t_msec	curnt;
};

struct s_config
{
	t_uint	cnt_philo;
	t_msec	delay_die;
	t_msec	delay_eat;
	t_msec	delay_sleep;
	int		cnt_eat;
};

struct s_data
{
	t_config	config;
	t_time		time_sys;
	t_mutex		key_print;
	t_func		routine[3];
};

struct s_philo
{
	t_uint	name;
	t_stat	stat;
	t_bool	fork;
	int		eating;
	t_time	timer_death;
	t_mutex	key_stat;
	t_mutex	key_fork_set;
	t_mutex	key_fork_ref;
};

struct s_thread
{
	pthread_t	id;
	pthread_t	id_monitor;
	t_philo		philo;
	t_data		*data;
};

struct s_list
{
	t_thread	*thread;
	t_list		*next;
	t_list		*prev;
};

/* DEBUG */
# include <stdio.h>

#endif