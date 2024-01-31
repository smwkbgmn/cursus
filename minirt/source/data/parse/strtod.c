/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 07:45:07 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/31 22:59:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void		valid_str(char *arg);
static void		valid_len(char *arg);

t_scl	ft_strtod(char *arg)
{
	t_scl	val;
	int		sign;

	valid_str(arg);
	valid_len(arg);
	if (*arg == '-')
	{
		sign = -1;
		arg++;
	}
	else
		sign = 1;
	val = ft_atoi(arg);
	arg = ft_strchr(arg, '.');
	if (arg)
		val += (t_scl)ft_atoi(arg + 1) / pow(10, ft_strlen(arg + 1));
	return (val * sign);
}

static void	valid_str(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	if (*arg == '.')
		err_usr("dot should be in between digits");
	while (ft_isdigit(*arg))
		arg++;
	if (*arg == '.' && *(arg + 1))
	{
		arg++;
		while (ft_isdigit(*arg))
			arg++;
	}
	if (*arg != '\0')
		err_usr("fail to get a value\n"
			"only digit, sign and a dot are allowed\n"
			"ensure numbers are fit in required form");
}

static void	valid_len(char *arg)
{
	t_bool	sign;
	char	*dot;

	if (!ft_strlen(arg))
		err_usr("empty field has found");
	sign = (*arg == '+' || *arg == '-');
	dot = ft_strchr(arg, '.');
	if (dot)
	{
		if (labs(arg - dot) > 7 + sign)
			err_usr("the value is too large to be used");
		else if (ft_strlen(dot + 1) > 7)
			err_usr("the value is too preciese to be used");
	}
	else
	{
		if (ft_strlen(arg) > 7 + sign)
			err_usr("the value is too large to be used");
	}
}
