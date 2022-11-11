/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:28:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/11 22:03:06 by jaeseule         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	unit(char *input, char **dict, int *len_p, char *tmp);
char	*cpy_to_tmp(char *input, char *tmp, int len);
int		parsing(char **dict, char *to_find);

void	print(char *input, char **dict)
{
	char	tmp[5];
	int		len;

	len = 0;
	while (input[len])
		len++;
	if (len == 1 && *input == '0')
		putstr(dict[parsing(dict, "0:")], 0);
	len--;
	while (len >= 0)
	{
		input = cpy_to_tmp(input, tmp, len);
		under_thousand(tmp, dict, &len);
		if (len % 3 == 2 && len >= 0)
			unit(input, dict, &len, tmp);
	}
}

void	unit(char *input, char **dict, int *len_p, char *tmp)
{
	char	buf[38];
	int		len;
	int		idx;

	len = *len_p;
	while (*input == '0' && *input)
		input++;
	if (tmp[0] == '0' && tmp[1] == '0' && tmp[2] == '0' && *input == 0)
		return ;
	buf[0] = 0;
	ft_strcat(buf, "1");
	while (len >= 0)
	{
		ft_strcat(buf, "0");
		len--;
	}
	ft_strcat(buf, ":");
	idx = parsing(dict, buf);
	if (*input == 0 && idx >= 0)
		putstr(dict[idx], 0);
	else if (*input != 0 && idx >= 0)
		putstr(dict[idx], 1);
	if (idx < 0)
		*len_p = -42;
}

char	*cpy_to_tmp(char *input, char *tmp, int len)
{
	int	idx;

	set_default(tmp);
	idx = 0;
	if (len % 3 == 0)
	{
		ft_strcat(tmp, "FF");
		idx = 2;
	}
	if (len % 3 == 1)
	{
		ft_strcat(tmp, "F");
		idx = 1;
	}
	while (idx < 3)
		tmp[idx++] = *input++;
	tmp[idx] = ':';
	return (input);
}

int	parsing(char **dict, char *to_find)
{
	int	r;
	int	c;

	r = 0;
	while (dict[r])
	{
		c = 0;
		while (dict[r][c] == to_find[c] && to_find[c])
			c++;
		if (to_find[c] == 0)
			return (r);
		r++;
	}
	write(1, "Dict Error\n", 11);
	return (-42);
}

void	putstr(char *dict_i_str, int len)
{
	while (*dict_i_str != ':' && *dict_i_str)
		dict_i_str++;
	dict_i_str++;
	while (*dict_i_str)
		write(1, dict_i_str++, 1);
	if (len > 0)
		write(1, " ", 1);
	else
		write(1, "\n", 1);
}
