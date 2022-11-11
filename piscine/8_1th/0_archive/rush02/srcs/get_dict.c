/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeseule <jaeseule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:42:23 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/11 23:30:29 by jaeseule         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_dict_str(char *f_name, int size, int *mall_chk);
void	get_dict_size(char *f_name, int *size, int *line, int *mall_chk);
void	split(char *str, char **dict, int *mall_chk);
int		get_length(char *str);

char	**get_dict(char *f_name, int *mall_chk)
{
	char	*dict_str;
	char	**dict;
	int		size;
	int		line;

	dict = 0;
	get_dict_size(f_name, &size, &line, mall_chk);
	dict_str = get_dict_str(f_name, size, mall_chk);
	if (dict_str == 0)
		return (0);
	dict = (char **)malloc(sizeof(char *) * (line));
	if (dict == 0)
	{
		free(dict);
		*mall_chk = 0;
		return (0);
	}
	split(dict_str, dict, mall_chk);
	if (*mall_chk == 0)
		return (0);
	free(dict_str);
	return (dict);
}

char	*get_dict_str(char *f_name, int size, int *mall_chk)
{
	char	*dict_str;
	int		fd;

	dict_str = (char *)malloc(sizeof(char) * size + 1);
	if (dict_str == 0)
	{
		free(dict_str);
		*mall_chk = 0;
		return (0);
	}
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		*mall_chk = 0;
		return (0);
	}
	if (read(fd, dict_str, size) < 0)
	{
		*mall_chk = 0;
		return (0);
	}
	close(fd);
	return (dict_str);
}

void	get_dict_size(char *f_name, int	*size, int *line, int *mall_chk)
{
	char	str[2];
	int		fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		*mall_chk = 0;
		return ;
	}
	*size = 0;
	*line = 0;
	while (read(fd, str, 1) == 1)
	{
		if (*str == '\n')
			*line += 1;
		*size += 1;
	}
	if (read(fd, str, 1) < 0)
		*mall_chk = 0;
	if (close(fd) < 0)
	{
		*mall_chk = 0;
		return ;
	}
}

void	split(char *str, char **dict, int *mall_chk)
{
	int	r;
	int	c;

	r = 0;
	while (*str)
	{
		dict[r] = (char *)malloc(sizeof(char) * (get_length(str) + 1));
		if (dict[r] == 0)
		{
			free_dict(dict, r);
			*mall_chk = 0;
			return ;
		}
		c = 0;
		str = split_tmp(str);
		while ('0' <= *str && *str <= '9')
			dict[r][c++] = *str++;
		str = split_tmpp(str);
		dict[r][c++] = ':';
		while (*str != '\n')
			dict[r][c++] = *str++;
		dict[r++][c] = 0;
		str++;
	}
	dict[r] = 0;
}

int	get_length(char *str)
{
	int	len;

	len = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		len++;
		str++;
	}
	while (*str == ' ' || *str == ':')
		str++;
	len++;
	while (*str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}
