/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:07 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 01:09:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

#include <stdlib.h>

static size_t	pass_flags(const char *str);
static char		*pad_space(char *value, int width);

char	*flag_dash(const char *str, char *value)
{
	char	*result;
	int		width;

	str += pass_flags(str);
	width = ft_atoi(str) - ft_strlen(value);
	if (width > 0)
		result = pad_space(value, width);
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

static char	*pad_space(char *value, int width)
{
	char	*result;
	char	*spaces;

	result = 0;
	spaces = malloc(width + 1);
	if (spaces)
	{
		ft_memset(spaces, ' ', width);
		result = ft_strjoin(value, spaces);
		free(value);
		free(spaces);
	}
	return (result);
}