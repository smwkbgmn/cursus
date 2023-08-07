/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:12:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/01 14:38:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "philo.h"

void	*test();

int	main(void)
{
	pthread_t	thred;

	pthread_create(&thred, NULL, &test, NULL);
	pthread_join(thred, NULL);
	return (0);
}

void	*test()
{
	printf("hello\n");
	return (NULL);
}
