/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/24 06:27:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

static char	*pad_zero(char *value, int num);

char	*flag_precision(const char *str, char *value)
{
	char	*result;
	int		width;

	while (!ft_isdigit(*str))
		str++;
	width = ft_atoi(str) - ft_strlen(value);
	if (width > 0)
		result = pad_zero(value, width);
	else if (width == -1 && *value == '0')
	{
		free(value);
		result = ft_calloc(1, 1);
	}
	else
		result = value;
	return (result);
}

static char	*pad_zero(char *value, int num)
{
	char	*result;
	char	*zeros;

	result = 0;
	zeros = malloc(num + 1);
	if (zeros)
	{
		ft_memset(zeros, '0', num);
		result = ft_strjoin(zeros, value);
		free(zeros);
		free(value);
	}
	return (result);
}
