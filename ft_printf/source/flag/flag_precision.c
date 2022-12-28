/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/28 13:04:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static char		*get_sign(char *value);
static size_t	pass_flags(const char *str);
static char		*pad_zero(char *value, char *sign, char *digit, int width);

char	*flag_precision(const char *str, char *value)
{
	char	*result;
	char	*sign;
	char	*digit;
	int		width;

	result = 0;
	sign = get_sign(value);
	if (sign)
	{
		digit = ft_strdup(value + ft_strlen(sign));
		if (digit)
		{
			str += pass_flags(str);
			width = ft_atoi(str) - ft_strlen(digit);
			if (width == -1 && *digit == '0')
				result = ft_strdup(sign);
			else
				result = pad_zero(value, sign, digit, width);
			free(value);
			free(digit);
		}
		free(sign);
	}
	return (result);
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
	else if (ft_strncmp(value, "0x", 2) == 0)
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

	if (width > 0)
	{
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
	}
	else
		result = ft_strdup(value);
	return (result);
}
