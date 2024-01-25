/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:21:25 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 08:10:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static char	*anchor(char *arg, int c);

t_vec	get_vec(char *arg, t_intvl intvl)
{
	t_scl	scl[3];
	int		idx;
	char	*comma;
	char	*substr;

	ft_memset(&scl, NONE, sizeof(t_scl) * 3);	
	idx = 0;
	while (idx < 3)
	{
		if (idx < 2)
		{
			comma = anchor(arg, ',');
			substr = try(ft_strdup_ptr(arg, comma));

			// dprintf(2, "substr [%s]\n", substr);
			
			scl[idx++] = get_scl(substr, intvl);
			ft_free(substr);
			arg = comma + 1;
		}
		else
			scl[idx++] = get_scl(arg, intvl);
	}
	return (vec(scl[0], scl[1], scl[2]));
}

static char	*anchor(char *arg, int c)
{
	char	*ptr;

	ptr = ft_strchr(arg, c);
	if (!ptr || ptr == arg)
		err_usr("three value with comma should be typed");
	return (ptr);
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
	// dprintf(2, "\tget_scl result [%f] from [%s]\n", val, arg);
	if (!contains(val, intvl))
		err_usr("ensure entered value is in range as required");
	return (val);
}
