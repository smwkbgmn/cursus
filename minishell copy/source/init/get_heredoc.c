/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:10:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:25:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "minishell.h"

static void		write_heredoc(int fd_heredoc, char *limiter);
static char		*read_from_stdin(int len);
static int		read_one_char(char *buf, int *byte_read);
static char		*init_line(size_t len);
static t_bool	is_limiter(char *line, char *limiter);

int	get_heredoc(char *tmpfile, char *delim)
{
	int	fd;

	fd = open_fd(tmpfile, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	write_heredoc(fd, delim);
	close_fd(fd);
	return (open_fd(tmpfile, O_RDONLY, 0));
}

static void	write_heredoc(int fd_heredoc, char *limiter)
{
	char	*line;

	write(STDIN_FILENO, ">", 1);
	line = read_from_stdin(0);
	if (line)
	{
		if (!is_limiter(line, limiter))
		{
			if (write(fd_heredoc, line, ft_strlen(line)) == ERROR)
				exit_error("write");
			write_heredoc(fd_heredoc, limiter);
		}
		ft_free(line);
	}
}

static char	*read_from_stdin(int len)
{
	char			*line;
	char			buf;
	int				byte_read;

	len += read_one_char(&buf, &byte_read);
	if (byte_read > 0 && buf != '\n')
		line = read_from_stdin(len);
	else
	{
		if (len > 0 || buf == '\n')
			line = init_line(len + 1);
		else
			line = NULL;
	}
	if (line && byte_read > 0)
		line[len - 1] = buf;
	return (line);
}

static int	read_one_char(char *buf, int *byte_read)
{
	*byte_read = read(STDIN_FILENO, buf, 1);
	if (*byte_read == ERROR)
		exit_error("read");
	return (*byte_read);
}

static char	*init_line(size_t len)
{
	return (calloc_erx(len, sizeof(char)));
}

static t_bool	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(line)) == 0
		|| (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(limiter)));
}
