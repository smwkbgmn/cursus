/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 01:28:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

#include <stdio.h>

static	short	check_is_flag_zero(const char *str);
static	char	*pad_space(char *value, int width);

char	*flag_width(const char *str, char *value)
{
	char	*result;
	int		width;

	result = value;
	if (*(str - 1) != '0' || check_is_flag_zero(str))
	{
		width = ft_atoi(str) - ft_strlen(value);
		if (width > 0)
			result = pad_space(value, width);
	}
	return (result);
}

static	short	check_is_flag_zero(const char *str)
{
	while (get_spcf(*str) == -1)
	{
		if (get_spcf(*str) == 3)
			return (0);
		str++;
	}
	return (1);
}

static	char	*pad_space(char *value, int width)
{
	char	*result;
	char	*spaces;

	result = 0;
	spaces = malloc(width + 1);
	if (spaces)
	{
		ft_memset(spaces, ' ', width);
		result = ft_strjoin(spaces, value);
		free(value);
		free(spaces);
	}
	return (result);
}
