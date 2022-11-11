/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:29:14 by pji               #+#    #+#             */
/*   Updated: 2022/06/08 22:06:08 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "read_file.h"
#include "square.h"
#include <unistd.h>
#include <stdlib.h>

char	**read_input(char *structure)
{
	int		col_len;
	char	**result;

	col_len = read_first(STDIN_FILENO, structure);
	if (col_len == 0)
		return (NULL);
	result = read_map(STDIN_FILENO, col_len);
	if (result == NULL)
		return (NULL);
	return (result);
}

void	*map_free(char **map, int count)
{
	if (count == FREE_MAP)
	{
		count = 0;
		while (map[count] != NULL)
			free(map[count++]);
		free(map);
		return (NULL);
	}
	while (--count)
		free(map[count]);
	free(map);
	return (NULL);
}
