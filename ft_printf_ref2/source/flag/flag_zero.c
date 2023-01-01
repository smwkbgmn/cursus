/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:48 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/28 13:04:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static short	check_override(const char *str);
static char		*get_sign(char *value);
static size_t	pass_flags(const char *str);
static char		*pad_zero(char *value, char *sign, char *digit, int width);

char	*flag_zero(const char *str, char *value)
{
	char	*result;
	char	*sign;
	char	*digit;
	int		width;

	if (check_override(str))
		return (value);
	result = 0;
	sign = get_sign(value);
	if (sign)
	{
		digit = ft_strdup(value + ft_strlen(sign));
		if (digit)
		{
			str += pass_flags(str);
			width = ft_atoi(str) - ft_strlen(digit) - ft_strlen(sign);
			if (width > 0)
				result = pad_zero(value, sign, digit, width);
			else
				result = value;
			free(digit);
		}
		free(sign);
	}
	return (result);
}

static short	check_override(const char *str)
{
	while (*str != '%')
		str--;
	while (get_spcf(*str) == -1)
	{
		if (get_flag(*str) == 3)
			return (1);
		str++;
	}
	return (0);
}

static char	*get_sign(char *value)
{
	char	*sign;

	if (*value == '+')
		sign = ft_strdup("+");
	else if (*value == '-')
		sign = ft_strdup("-");
	else if (*value == ' ')
		sign = ft_strdup(" ");
	else if (*(value + 1) == 'x')
		sign = ft_strdup("0x");
	else
		sign = ft_strdup("\0");
	return (sign);
}

static size_t	pass_flags(const char *str)
{
	size_t	idx;

	idx = 1;
	while (!ft_isdigit(str[idx]) && get_spcf(str[idx]) == -1)
		idx++;
	return (idx);
}

static char	*pad_zero(char *value, char *sign, char *digit, int width)
{
	char	*result;
	char	*zeros;
	char	*sign_zeros;

	result = 0;
	zeros = malloc(width + 1);
	if (zeros)
	{
		ft_memset(zeros, '0', width);
		sign_zeros = ft_strjoin(sign, zeros);
		if (sign_zeros)
		{
			result = ft_strjoin(sign_zeros, digit);
			free(sign_zeros);
		}
		free(zeros);
	}
	free(value);
	return (result);
}
