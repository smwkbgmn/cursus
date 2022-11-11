/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:49:33 by pji               #+#    #+#             */
/*   Updated: 2022/06/08 22:05:29 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft.h"
#include "read_file.h"
#include "read_input.h"
#define FREE_MAP -1
#define EOF 0x1A

char	**read_file(char *file_name, char *icon)
{
	int		filds;
	int		col_len;
	char	**result;
	char	*row;

	filds = open(file_name, O_RDONLY);
	if (filds == -1)
		return (NULL);
	col_len = read_first(filds, icon);
	if (col_len == 0)
		return (NULL);
	result = read_map(filds, col_len);
	if (result == NULL)
		return (NULL);
	row = read_file_row(filds, 0);
	if (row[0])
	{
		free(row);
		return (map_free(result, FREE_MAP));
	}
	else
		free(row);
	close(filds);
	return (result);
}

char	*read_file_row(int filds, int size)
{
	char	a;
	char	*result;

	read(filds, &a, 1);
	if (a != '\n' && a != '\0')
	{
		result = read_file_row(filds, size + 1);
		if (result == NULL)
			return (result);
		result[size] = a;
	}
	else
	{
		result = malloc(sizeof(char) * (size + 1));
		if (result == NULL)
			return (result);
		result[size] = '\0';
	}
	return (result);
}

char	**read_map(int filds, int len_col)
{
	int		len_row;
	int		count;
	char	**result;

	count = 1;
	result = (char **)malloc(sizeof(char *) * (len_col + 1));
	if (result == NULL)
		return (NULL);
	result[len_col] = NULL;
	result[0] = read_file_row(filds, 0);
	if (result[0] == NULL)
		return (map_free(result, count));
	len_row = ft_strlen(result[0]);
	if (!len_row)
		return (NULL);
	while (count < len_col)
	{
		result[count] = read_file_row(filds, 0);
		if (result[count] == NULL)
			return (map_free(result, count));
		if (len_row != ft_strlen(result[count]))
			return (map_free(result, count));
		++count;
	}
	return (result);
}

int	read_first(int filds, char *icon)
{
	char	*row;
	int		row_len;
	int		col_len;
	int		count;

	row = read_file_row(filds, 0);
	if (row == NULL)
		return (0);
	row_len = ft_strlen(row);
	if (row_len < 4)
		return (free_row(row));
	ft_strcpy(icon, row + row_len - 3);
	if (icon[0] == icon[1] || icon[0] == icon[2] || icon[1] == icon[2])
		return (free_row(row));
	col_len = 0;
	count = 0;
	while (count < row_len - 3)
	{
		if (row[count] < '0' || row[count] > '9')
			return (free_row(row));
		col_len = col_len * 10 + row[count++] - '0';
	}
	free(row);
	return (col_len);
}

int	free_row(char *row)
{
	free(row);
	return (0);
}
