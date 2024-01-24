/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:21:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/23 16:17:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include "minirt.h"

static char	*anchor(char *arg, int c);

t_vec	get_vec(char *arg, t_intvl intvl)
{
	t_scl	val[3];
	char	*comma;
	char	*substr;
	int		idx;

	idx = 0;
	ft_memset(&val, NONE, sizeof(t_scl) * 3);	
	while (idx < 3)
	{
		if (idx < 2)
		{
			comma = anchor(arg, ',');
			substr = try(ft_strdup_ptr(arg, comma));

			// dprintf(2, "substr [%s]\n", substr);
			
			val[idx++] = get_scl(substr, intvl);
			ft_free(substr);
			arg = comma + 1;
		}
		else
			val[idx++] = get_scl(arg, intvl);
	}
	return (vec(val[0], val[1], val[2]));
}

static char	*anchor(char *arg, int c)
{
	char	*achr;

	achr = ft_strchr(arg, c);
	if (!achr || achr == arg)
		err_usr("three value with comma should be typed");
	return (achr);
}

// DBL_MIN ~ DBL_MAX
t_point	get_point(char *arg)
{
	// return (get_vec(arg, interval_set(DBL_MIN, DBL_MAX)));
	return (get_vec(arg, interval_set(-10000, 10000)));
}

// 0 ~ CLR_SCALE
t_color	get_color(char *arg)
{
	return (get_vec(arg, interval_set(0, CLR_SCALE)));
	// return (albedo_rgb(get_vec(arg, interval_set(0, CLR_SCALE)), 1));
}

static t_scl	str_value(char *arg);
static void		valid_str(char *arg);

t_scl	get_scl(char *arg, t_intvl intvl)
{
	t_scl	val;

	val = str_value(arg);
	// dprintf(2, "\tget_scl result [%f] from [%s]\n", val, arg);
	if (!contains(val, intvl))
		err_usr("ensure entered value is in range as required");
	return (val);
}

static t_scl	str_value(char *arg)
{
	t_scl	val;
	int		sign;

	valid_str(arg);
	val = ft_atoi(arg);
	if (val < 0)
	{
		sign = -1;
		val *= -1;
	}
	else
		sign = 1;
	arg = ft_strchr(arg, '.');
	if (arg)
		val += (t_scl)ft_atoi(arg + 1) / pow(10, ft_strlen(arg + 1));
	return (val * sign);
}

static void	valid_str(char *arg)
{
	// dprintf(2, "valid_str input [%s]\n", arg);
	// if (ft_strlen(arg) > 8)
	// 	err_usr("the value has too large number");
	if (*arg == '+' || *arg == '-')
		arg++;
	if (*arg == '.')
		err_usr("dot should be in between digits");
	while (ft_isdigit(*arg))
		arg++;
	if (*arg == '.')
	{
		arg++;
		while (ft_isdigit(*arg))
			arg++;
	}
	if (*arg != '\0')
		err_usr("fail to get a value.\nensure that only digit, sign and a dot are allowed");
}
