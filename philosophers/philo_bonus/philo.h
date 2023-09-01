/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:00:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 00:48:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

# define SUCCESS 0
# define ERROR -1
# define LOOP 1

typedef struct timeval		t_timeval;
typedef unsigned long long	t_msec;
typedef unsigned int		t_uint;

typedef enum e_bool			t_bool;
typedef enum e_switch		t_switch;
typedef enum e_stat			t_stat;
typedef enum e_keyname		t_keyname;

typedef struct s_list		t_list;
typedef struct s_process	t_process;
typedef struct s_info		t_info;
typedef struct s_vars		t_vars;
typedef struct s_config		t_config;
typedef struct s_time		t_time;

typedef void				(*t_func)(t_list *);

/* DATA */
t_bool	validate_input(int ac, char **av);

void	init_share(int ac, char **av, t_vars *share);

void	init_philosophers(t_list **data, t_vars *prgm);
char	*ft_itoa(t_uint num);

void	*errext(void *ptr);
void	exit_with_error(t_list *data, char *msg);
void	exit_test(t_vars *share, char *msg);

void	free_data(t_list *data, t_vars *share);
void	del_semaphore(t_list *data);

/* UTILL */
t_bool	config_can_not_continue(t_list *data);

void	create_thread(t_list *data, pthread_t *id, void *function);
void	join_thread(t_list *data, pthread_t *id);
void	detach_thread(t_list *data, pthread_t *id);

void	print_status(t_list *data, t_stat stat);
void	print_taking(t_list *data);
void	print_death(t_list *data);

// void	suspend(t_msec ms);
void	suspend(t_list *data, t_msec ms);
void	set_time(t_list *data, t_msec *time);
t_msec	get_time_elapsed(t_list *data, t_msec *start);

void	set_status(t_list *data, t_stat stat_to_change);
t_stat	ref_status(t_list *data);

sem_t	*init_sem(char *name, t_uint value);
void	free_sem(t_list *data, sem_t *key);
void	semaphore(t_list *data, t_keyname name, t_switch in);

/* LIFE */
void	start_life(t_list *data);

void	life(t_list *data);
void	philo_think(t_list *data);
void	philo_eat(t_list *data);
void	philo_sleep(t_list *data);

void	taking(t_list *data);
void	putting_down(t_list *data);

void	life_one(t_list *data);

void	start_timer(t_list *data);
void	detach_timer(t_list *data);

void	*timer(void *arg);

void	start_monitor(t_list *data);
void	join_monitor(t_list *data);

enum e_bool
{
	FALSE,
	TRUE
};

enum e_switch
{
	OUT,
	IN
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
	FORK_L,
	FORK_R,
	TIMER
};

struct s_config
{
	t_uint	cnt_philo;
	t_msec	time_die;
	t_msec	time_eat;
	t_msec	time_sleep;
	int		cnt_eat;
};

struct s_vars
{
	t_config	config;
	t_msec		time_life_begin;
	t_uint		cnt_done_eat;
	t_bool		death;
	t_func		routine[4];
	pthread_t	id_mntr_death;
	pthread_t	id_mntr_eaten;
	sem_t		*key[5];
};

struct s_info
{
	t_uint	name;
	t_stat	stat;
	int		eating;
	t_msec	time_last_meal;
	sem_t	*key_timer;
};

struct s_process
{
	pid_t		id;
	pthread_t	id_timer;
	t_info		info;
};

struct s_list
{
	t_process	*philo;
	t_vars		*share;
	t_list		*next;
	t_list		*prev;
};

#endif