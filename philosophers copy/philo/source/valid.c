/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:30:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 21:19:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	validate_argv(char **av);
static t_bool	validate_line(char *av);
static t_uint	ft_strlen(char *str);
static t_bool	is_digit(char c);

t_bool	validate_input(int ac, char **av)
{
	if (ac == 5 || ac == 6)
		return (validate_argv(av + 1));
	else
		return (FALSE);
}

static t_bool	validate_argv(char **av)
{
	if (*av)
	{
		if (validate_line(*av))
			return (validate_argv(av + 1));
		else
			return (FALSE);
	}
	else
		return (TRUE);
}

static t_bool	validate_line(char *av)
{
	if (ft_strlen(av) > 0)
	{
		while (is_digit(*av))
			av++;
		return (*av == '\0');
	}
	else
		return (FALSE);
}

static t_uint	ft_strlen(char *str)
{
	t_uint	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
