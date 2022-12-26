/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:29 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/27 03:20:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static short	check_override(char *value);
static short	check_case(const char *str);

char	*flag_hash(const char *str, char *value)
{
	char	*result;

	result = value;
	if (!check_override(value))
	{
		if (check_case(str) == 0)
			result = ft_strjoin("0x", value);
		else
			result = ft_strjoin("0X", value);
		free(value);
	}
	return (result);
}

static short	check_override(char *value)
{
	return (ft_strncmp(value, "0x", 2) == 0
		|| ft_strncmp(value, "0X", 2) == 0);
}

static short	check_case(const char *str)
{
	while (get_spcf(*str) == -1)
		str++;
	return (*str == 'X');
}
