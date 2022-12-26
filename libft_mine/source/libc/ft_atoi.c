/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:44 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/26 06:45:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pass_space(const char **str);
static int	get_sign(const char **str);
static int	get_int(const char **str, int sign);

int	ft_atoi(const char *str)
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

static int	get_sign(const char **str)
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

static int	get_int(const char **str, int sign)
{
	long	num;

	num = 0;
	while (ft_isdigit(**str))
		num = (num * 10) + ((*(*str)++ - '0') * sign);
	if (num * sign < 0)
		return ((sign > 0) * -1);
	else
		return (num);
}
