/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:21:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/31 23:01:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static t_bool	valid_comma(char *arg);

t_vec	get_vec(char *arg, t_intvl intvl)
{
	char	**argv;
	t_vec	vector;

	valid_comma(arg);
	argv = try(ft_split(arg, ','));
	vector.x = get_scl(argv[0], intvl);
	vector.y = get_scl(argv[1], intvl);
	vector.z = get_scl(argv[2], intvl);
	free_argv(argv);
	return (vector);
}

static t_bool	valid_comma(char *arg)
{
	char	*anchor;
	int		cnt_comma;

	cnt_comma = 0;
	while (LOOP)
	{
		anchor = ft_strchr(arg, ',');
		if (anchor && ++cnt_comma < 3)
		{
			if (anchor == arg || *(anchor + 1) == '\0')
				err_usr("empty field in vector has found");
			arg = anchor + 1;
			continue ;
		}
		break ;
	}
	if (cnt_comma != 2)
		err_usr("ensure there are 3 values in vector");
	return (TRUE);
}

t_point	get_point(char *arg)
{
	return (get_vec(arg, interval(-SCL_MAX, SCL_MAX)));
}

t_color	get_color(char *arg)
{
	return (get_vec(arg, interval(0, CLR_SCALE)));
}

t_scl	get_scl(char *arg, t_intvl intvl)
{
	t_scl	val;

	val = ft_strtod(arg);
	if (!contains(val, intvl))
		err_usr("ensure entered value is in range as required");
	return (val);
}
