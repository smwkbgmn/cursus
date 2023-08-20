/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:06:43 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/15 18:08:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_uint	ft_strlen(char *str)
{
	t_uint	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

t_uint	ft_atoi(char *av)
{
	t_uint	num;

	num = 0;
	while (*av)
	{
		num = num * 10 + (*av - '0');
		av++;
	}
	return (num);
}
