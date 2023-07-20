/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:38:43 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 03:05:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "pipex.h"

static t_bool	is_heredoc(char *av_heredoc);
static void		write_heredoc(int fd_heredoc, char *limiter);
static t_bool	is_limiter(char *line, char *limiter);
// char			*read_from_stdin(t_uint len);

void	init_heredoc(t_data *input, char *av_heredoc, char *av_limiter)
{
	if (is_heredoc(av_heredoc))
	{
		input->heredoc = TRUE;
		write_heredoc(open_fd("heredoc",
				O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644), av_limiter);
	}
	else
		input->heredoc = FALSE;
}

static t_bool	is_heredoc(char *av_heredoc)
{
	return (ft_strncmp(av_heredoc, "here_doc", ft_strlen(av_heredoc)) == 0);
}

// void	write_heredoc(int fd_heredoc, char *limiter)
// {
// 	char	*line;

// 	line = read_from_stdin(0);
// 	ft_printf("line : %s", line);
// 	if (line)
// 	{
// 		if (!is_limiter(line, limiter))
// 		{
// 			write(fd_heredoc, line, ft_strlen(line));
// 			write_heredoc(fd_heredoc, limiter);
// 		}
// 		else
// 			close_fd(fd_heredoc);
// 		ft_free(line);
// 	}
// }

static void	write_heredoc(int fd_heredoc, char *limiter)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (line)
	{
		if (!is_limiter(line, limiter))
		{
			write(fd_heredoc, line, ft_strlen(line));
			write_heredoc(fd_heredoc, limiter);
		}
		else
			close_fd(fd_heredoc);
		ft_free(line);
	}
}

static t_bool	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(line)) == 0
		|| (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(limiter)));
}

char	*read_from_stdin(t_uint len)
{
	char	*line;
	char	buf;

	if (read(STDIN_FILENO, &buf, 1) == ERROR)
		exit_with_error("read");
	if (buf != '\n' && buf != '\0')
		line = read_from_stdin(len + 1);
	else if (buf == '\n' || len > 0)
	{
		line = ft_calloc(len + (buf == '\n'), sizeof(char));
		if (!line)
			exit_with_error("malloc");
	}
	else
		line = NULL;
	if (line)
		line[len] = buf;
	return (line);
}
