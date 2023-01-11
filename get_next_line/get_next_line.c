/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/11 13:28:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Consider standard input (fd 1)
// Read buf size will be modified during evaluation
// compiler buf size flag : -D BUFFER_SIZE=n

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
}

short	find_newline(char *buf)
{
	while (buf)
	{
		if (*buf == '\n')
			return (TRUE);
		buf++;
	}
	return (FALSE);
}

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		buf[1];
// 	static int	len_out;
// 	int			len_in;

// 	if (fd == ERROR)
// 		return (NULL);
// 	len_in = read(fd, buf, 1);
	// printf("check len_in & buf --- [%d], [%c]\n", len_in, buf[0]);
// 	if (buf[0] == '\n' || len_in == 0 || len_in == -1)
// 	{
		// printf("### you entered end point ###\n");
// 		if (buf[0] == '\n')
// 			len_out++;
// 		if (len_out > 0)
// 		{
// 			line = malloc(len_out + 1);
// 			line[len_out] = 0;
// 		}
// 		else
// 			line = NULL;
// 	}
// 	else
// 	{
		// printf("keep going --- [%d]\n", len_out);
// 		len_out += len_in;
// 		line = get_next_line(fd);
// 	}
// 	len_out--;
// 	if (line && len_in > 0)
// 	{
// 		line[len_out] = buf[0];
		// printf("after end point --- [%c]\n", line[len_out]);
// 	}
// 	return (line);
// }
