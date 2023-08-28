/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:32:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 04:28:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0

typedef struct timeval		t_timeval;
typedef unsigned long long	t_msec;
typedef unsigned int		t_uint;
typedef pthread_mutex_t		t_mutex;

typedef enum e_bool			t_bool;
typedef enum e_switch		t_switch;
typedef enum e_stat			t_stat;
typedef enum e_keyname		t_keyname;

typedef struct s_list		t_list;
typedef struct s_thread		t_thread;
typedef struct s_philo		t_philo;
typedef struct s_vars		t_vars;
typedef struct s_config		t_config;
typedef struct s_time		t_time;

typedef void				(*t_func)(t_list *);

/* DATA */
t_bool	validate_input(int ac, char **av);

t_bool	init_program(int ac, char **av, t_vars *prgm);
t_bool	init_philosophers(t_list **data, t_vars *prgm);

void	free_data(t_list *data, t_vars *prgm);

/* UTILL */
void	print_status(t_list *data, t_stat stat);
void	print_taking(t_list *data);
void	print_death(t_list *data);

void	suspend(t_msec ms);
void	set_time(t_list *data, t_msec *time_ms);
t_msec	get_time_elapsed(t_list *data, t_time *time);

void	mutex(t_list *data, t_keyname name, t_switch lock);
t_bool	init_keys(t_mutex *key);
void	mtx_free(t_mutex *key);

void	set_philos_eating(t_list *data);
t_uint	ref_philos_eating(t_list *data);
t_bool	meet_philos_eating(t_list *data);

void	set_status(t_list *data, t_stat stat_to_change);
t_stat	ref_status(t_list *data);
void	set_death(t_list *data);
t_bool	ref_death(t_list *data);

/* THREAD */
void	start_life(t_list *data);

void	init_philos_odd(t_list *data, t_uint cnt);
void	init_philos_even(t_list *data, t_uint cnt);
void	join_philos(t_list *data, t_uint cnt);
void	join_monitors(t_list *data, t_uint cnt);

void	*life(void *arg);
void	philo_think(t_list *data);
void	philo_eat(t_list *data);
void	philo_sleep(t_list *data);

void	taking(t_list *list);
void	putting_down(t_list *list);

void	*monitor(void *arg);

void	*life_one(void *arg);

enum e_bool
{
	FALSE,
	TRUE
};

enum e_switch
{
	OFF,
	ON
};

enum e_stat
{
	THINK,
	STARVE,
	EAT,
	SLEEP
};

enum e_keyname
{
	EATING,
	DEATH,
	PRINT,
	STAT,
	FORK,
	TIMER
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

struct s_vars
{
	t_config	config;
	t_time		time_sys;
	t_uint		philo_meet_eating;
	t_bool		philo_death;
	t_func		routine[4];
	t_mutex		key[3];
};

struct s_philo
{
	t_uint	name;
	t_stat	stat;
	int		eating;
	t_time	timer_die;
	t_mutex	key[3];
};

struct s_thread
{
	pthread_t	id;
	pthread_t	id_monitor;
	t_philo		philo;
};

struct s_list
{
	t_thread	*thread;
	t_vars		*program;
	t_list		*next;
	t_list		*prev;
};

/* DEBUG */
# include <stdio.h>

#endif