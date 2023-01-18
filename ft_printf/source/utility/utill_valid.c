/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:40:39 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/16 03:53:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libftprintf.h"

static size_t	find_format(const char *str);
static short	valid_width(char *format);
static char		*find_digit(char **format);
static char		*pass_digit(char **format);

short	valid_format(const char *str)
{
	char	*format;
	short	valid;

	str += find_format(str);
	if (*str == '\0')
		valid = TRUE;
	else
	{
		format = ft_substr(str, 1, get_len_format(str));
		if (format)
		{
			valid = valid_width(format);
			free(format);
		}
		else
			valid = FALSE;
	}
	return (valid);
}

static size_t	find_format(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '%' && str[idx])
		idx++;
	return (idx);
}

static short	valid_width(char *format)
{
	long	width;

	while (*format)
	{
		width = ft_atoi_long(find_digit(&format));
		if (width < 0 || width > 2147483646)
			return (FALSE);
		else
			pass_digit(&format);
	}
	return (TRUE);
}

static char	*find_digit(char **format)
{
	while (!ft_isdigit(**format) && **format)
		(*format)++;
	return (*format);
}

static char	*pass_digit(char **format)
{
	while (ft_isdigit(**format) && **format)
		(*format)++;
	return (*format);
}
