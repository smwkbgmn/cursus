/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:06:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 17:02:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static char		*read_from_stdin(t_uint len);
static void		read_one_char(char *buf, int *byte_read);
static char		*init_line(t_uint len);
static t_bool	is_limiter(char *line, char *limiter);

void	write_heredoc(int fd_heredoc, char *limiter)
{
	char	*line;

	line = read_from_stdin(0);
	if (line)
	{
		if (!is_limiter(line, limiter))
		{
			if (write(fd_heredoc, line, ft_strlen(line)) == ERROR)
				exit_with_error("write");
			write_heredoc(fd_heredoc, limiter);
		}
		else
			close_fd(fd_heredoc);
		ft_free(line);
	}
}

static char	*read_from_stdin(t_uint len)
{
	char	*line;
	char	buf;
	int		byte_read;

	read_one_char(&buf, &byte_read);
	if (buf != '\n' && byte_read > 0)
		line = read_from_stdin(len + 1);
	else
	{
		if (buf == '\n' || len > 0)
			line = init_line(len + 1 + (buf == '\n'));
		else
			line = NULL;
	}
	if (line)
		line[len] = buf;
	return (line);
}

static void	read_one_char(char *buf, int *byte_read)
{
	*byte_read = read(STDIN_FILENO, buf, 1);
	if (*byte_read == ERROR)
		exit_with_error("read");
}

static char	*init_line(t_uint len)
{
	return (catcher(ft_calloc(len, sizeof(char))));
}

static t_bool	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(line)) == 0
		|| (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(limiter)));
}
