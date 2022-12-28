/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:48 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 03:32:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static size_t	pass_flags(const char *str);
static short	check_override(const char *str);
static short	check_flag_sign(const char *str, short sign);
static char		*pad_zero(char *value, int width, short sign);

// char	*flag_zero(const char *str, char *value)
// {
// 	char	*result;
// 	int		width;
// 	short	sign;

// 	if (check_override(str))
// 		return (value);
// 	sign = (*value == '-');
// 	str += pass_flags(str);
// 	width = ft_atoi(str) - ft_strlen(value) - check_flag_sign(str, sign);
// 	if (width > 0)
// 		result = pad_zero(value, width, sign);
// 	else
// 		result = value;
// 	return (result);
// }

char	*flag_zero(const char *str, char *value)
{
	char	*result;
	int		width;
	short	sign;

	result = value;
	if (!check_override(str))
	{
		sign = (*value == '-');
		str += pass_flags(str);
		width = ft_atoi(str) - ft_strlen(value) - check_flag_sign(str, sign);
		if (width > 0)
			result = pad_zero(value, width, sign);
	}
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

static short	check_override(const char *str)
{
	if (*(str - 1) == '.' || *(str - 1) == '0')
		return (1);
	while (get_spcf(*str) == -1)
	{
		if (get_flag(*str) == 0)
			return (1);
		str++;
	}
	return (0);
}

static short	check_flag_sign(const char *str, short sign)
{
	if (sign == 1)
		return (0);
	while (*str != '%')
		str--;
	while (get_spcf(*str) == -1)
	{
		if (*str == '+' || *str == ' ')
			return (1);
		else if (*str == '#')
			return (2);
		str++;
	}
	return (0);
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
