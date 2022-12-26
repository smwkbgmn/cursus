/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:41 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 03:02:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static short	check_overide(char *value);

char	*flag_plus(const char *str, char *value)
{
	char	*result;

	str++;
	result = value;
	if (!check_overide(value))
	{
		result = ft_strjoin("+", value);
		free(value);
	}
	return (result);
}

static short	check_overide(char *value)
{
	return (*value == '-' || *value == '+');
}
