/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:44 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/12 20:14:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pass_space(const char **str);
static short	get_sign(const char **str);
static long		get_int(const char **str, short sign);

long	ft_atoi_long(const char *str)
{
	if (*str == 0)
		return (0);
	else
	{
		pass_space(&str);
		return (get_int(&str, get_sign(&str)));
	}
}

static void	pass_space(const char **str)
{
	while ((9 <= **str && **str <= 13) || **str == ' ')
		(*str)++;
}

static short	get_sign(const char **str)
{
	if (**str == '+' || **str == '-')
	{
		if (*(*str)++ == '-')
			return (-1);
		else
			return (1);
	}
	else
		return (1);
}

static long	get_int(const char **str, short sign)
{
	long	num;

	num = 0;
	while (ft_isdigit(**str))
		num = (num * 10) + ((*(*str)++ - '0') * sign);
	return (num);
}
