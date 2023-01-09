/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/09 21:39:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[2];
	static int	len_out;
	int			len_in;

	if (fd == ERROR)
		return (NULL);
	len_in = read(fd, buffer, 1);
	printf("check len_in & buffer --- [%d], [%c]\n", len_in, buffer[0]);
	if (buffer[0] == '\n' || len_in == 0 || len_in == -1)
	{
		printf("you entered end point\n");
		if (buffer[0] == '\n')
			len_out += len_in;
		line = malloc(len_out + 1);
		line[len_out] = 0;
	}
	else
	{
		printf("keep going --- [%d]\n", len_out);
		len_out += len_in;
		line = get_next_line(fd);
	}
	line[--len_out] = buffer[0];
	printf("after end point --- [%c]\n", line[len_out]);
	return (line);
}
