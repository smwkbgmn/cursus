/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:51:01 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 23:00:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_dict(char **dict, int r)
{
	while (r >= 0)
	{
		free(dict[r]);
		r--;
	}
	free(dict);
}

void	free_all(char *f_name, char *input, char **dict)
{
	int	r;

	r = 0;
	while (dict[r])
	{
		free(dict[r]);
		r++;
	}
	free(dict[r]);
	free(dict);
	free(f_name);
	free(input);
}

char	*split_tmp(char *str)
{
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		str++;
	return (str);
}

char	*split_tmpp(char *str)
{
	while (*str != ':')
		str++;
	str++;
	while (*str == ' ')
		str++;
	return (str);
}

char	*apply_atoi_rule_tmp(char *av)
{
	while ((9 <= *av && *av <= 13) || *av == ' ')
		av++;
	if (*av == '+')
		av++;
	while (*av == '0')
		av++;
	return (av);
}
