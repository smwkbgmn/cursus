/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:07:27 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 20:25:40 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *b, int n, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((unsigned char *)b)[i] = (unsigned char) n;
		i++;
	}
	return (b);
}


int	ft_init_all(int ac, char **av, t_arg *arg,t_philo  **philo)
{
	if(init_args(arg, ac, av) != 0)
	{
		printf("Argument init Error!\n");
		return (1);
	}
	if(init_philo(philo, arg) != 0)
	{
		printf("Philosopher init Error!\n");
		return (1);
	}
	if(make_philo(arg, *philo) != 0)
	{
		printf("Philosopher thread Error!\n");
		return (1);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_arg	arg;
	t_philo	*philo;

	if (ac < 5 || ac > 6)
	{
		printf("arument error!\n");
        return (1);
	}
	else
	{
		ft_memset(&arg, 0, sizeof(t_arg));
		if(ft_init_all(ac, av, &arg, &philo) != 0)
			return (1);
	}
	destroy_mutex(&arg);
	return (0);
}