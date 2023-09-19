/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:07:42 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 22:09:34 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>


typedef struct s_philo
{
	struct s_arg			*arg;
	pthread_t				thread;
	int						id;
	int						left;
	int						right;
	unsigned long long		last_eat_time;
	int						eat_count;
}				t_philo;

typedef struct s_arg
{
	int						num_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_meals;
	int						end_flag;
	int						end_meal_count;
	int						*fork_flag;
	unsigned long long		start_time;
	pthread_mutex_t			*forks;
	pthread_mutex_t			init_thread;
	pthread_mutex_t			print;
	pthread_mutex_t			end_mutex;
	pthread_mutex_t			count_mutex;
	pthread_mutex_t			time;
}				t_arg;

void				destroy_mutex(t_arg *arg);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned long long	ft_atoi(const char *str);
void				sleep_even(t_arg *arg);
unsigned long long	current_time(void);
int					check_digit(char *str);
void				spend_time(unsigned long long wait_time, t_arg *arg);
int					init_mutex(t_arg *arg);
int					init_args(t_arg *arg, int argc, char **argv);
int					init_philo(t_philo **philo, t_arg *arg);
int					print_philo(t_arg *arg, int id, char *msg);
int					get_fork_eating(t_arg *arg, t_philo *philo);
void				monitor(t_arg *arg, t_philo *philo);
int					make_philo(t_arg *arg, t_philo *philo);
void				*thread_start(void *argv);

#endif