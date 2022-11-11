/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:38:34 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 20:05:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hundred(char *tmp, char **dict, int *len, char *buf);
void	ten(char *tmp, char **dict, int *len, char *buf);
void	one(char *tmp, char **dict, int *len, char *buf);

void	under_thousand(char *tmp, char **dict, int *len)
{
	char	buf[5];
	int		idx;

	idx = 0;
	while (idx < 3 && *len >= 0)
	{
		set_default(buf);
		if (tmp[idx] != '0' && tmp[idx] != 'F')
		{
			if (idx == 0)
				hundred(tmp, dict, len, buf);
			else if (idx == 1)
			{
				ten(tmp, dict, len, buf);
				if (tmp[1] == '1')
					break ;
			}
			else
				one(tmp, dict, len, buf);
		}
		if (tmp[idx] != 'F')
			*len -= 1;
		idx++;
	}
}

void	hundred(char *tmp, char **dict, int *len, char *buf)
{
	int	idx;

	*buf = tmp[0];
	ft_strcat(buf, ":");
	idx = parsing(dict, buf);
	if (idx < 0)
	{
		*len = -42;
		return ;
	}
	putstr(dict[idx], *len);
	ft_strcpy(buf, "100:");
	if (*len == 2 && tmp[1] == '0' && tmp[2] == '0')
		*len -= 2;
	idx = parsing(dict, buf);
	if (idx < 0)
	{
		*len = -42;
		return ;
	}
	putstr(dict[idx], *len);
}

void	ten(char *tmp, char **dict, int *len, char *buf)
{
	int	idx;

	if (tmp[1] > '1')
	{
		*buf = tmp[1];
		ft_strcat(buf, "0:");
		if (*len == 1 && tmp[2] == '0')
			*len -= 1;
		idx = parsing(dict, buf);
		if (idx >= 0)
			putstr(dict[idx], *len);
	}
	if (tmp[1] == '1')
	{
		buf[0] = tmp[1];
		buf[1] = tmp[2];
		buf[2] = tmp[3];
		*len -= 2;
		idx = parsing(dict, buf);
		if (idx >= 0)
			putstr(dict[idx], *len);
	}
	if (idx < 0)
		*len = -42;
}

void	one(char *tmp, char **dict, int *len, char *buf)
{
	int	idx;

	ft_strcat(buf, &tmp[2]);
	idx = parsing(dict, buf);
	if (idx < 0)
	{
		*len = -42;
		return ;
	}
	putstr(dict[parsing(dict, buf)], *len);
}
