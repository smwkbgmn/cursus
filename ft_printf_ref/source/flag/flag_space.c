/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:45 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 02:54:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static short	check_overide(const char *str, char *value);

char	*flag_space(const char *str, char *value)
{
	char	*result;

	result = value;
	if (!check_overide(str, value))
	{
		result = ft_strjoin(" ", value);
		free(value);
	}
	return (result);
}

static short	check_overide(const char *str, char *value)
{
	while (*str != '%')
		str--;
	while (get_spcf(*str) == -1)
	{
		if (*str == '+')
			return (1);
		str++;
	}
	return (*value == '-');
}
