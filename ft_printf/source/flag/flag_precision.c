/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/26 12:06:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>
#include <stddef.h>

static size_t	pass_flags(const char *str);
static char		*pad_zero(char *value, int width, short sign);

char	*flag_precision(const char *str, char *value)
{
	char	*result;
	int		width;
	short	sign;

	str += pass_flags(str);
	sign = (*value == '-');
	width = ft_atoi(str) - ft_strlen(value + sign);
	if (width > 0)
		result = pad_zero(value, width, sign);
	else if (width == -1 && *value == '0')
	{
		result = ft_calloc(1, 1);
		free(value);
	}
	else
		result = value;
	return (result);
}

static size_t	pass_flags(const char *str)
{
	size_t	idx;

	idx = 1;
	while (!ft_isdigit(str[idx]) && get_spcf(str[idx]) == -1)
		idx++;
	return (idx);
}

static char	*pad_zero(char *value, int width, short sign)
{
	char	*result;
	char	*zeros;

	result = 0;
	zeros = malloc(width + sign + 1);
	if (zeros)
	{
		if (sign == 1)
			*zeros = '-';
		ft_memset(zeros + sign, '0', width);
		result = ft_strjoin(zeros, value + sign);
		free(zeros);
		free(value);
	}
	return (result);
}
