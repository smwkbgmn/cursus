/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:10:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 16:47:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static void		write_heredoc(int fd_heredoc, char *limiter);
static char		*expand_env(char *line);
static char		*copy_buf(char *expanded, char *buf, size_t *len);
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
	char	*expanded;

	line = readline(">");
	if (line)
	{
		expanded = expand_env(line);
		free(line);
		line = expanded;
		if (!is_limiter(line, limiter))
		{
			ft_putstr_fd(line, fd_heredoc);
			ft_putstr_fd("\n", fd_heredoc);
			write_heredoc(fd_heredoc, limiter);
		}
		ft_free(line);
	}
}

static char	*expand_env(char *line)
{
	static size_t	len;
	char			*expanded;
	char			*buf;

	if (*line)
	{
		if (*line == DOLR)
			buf = expand_env_var(&line);
		else
		{
			buf = calloc_erx(2, 1);
			*buf = *line++;
		}
		len += ft_strlen(buf);
		expanded = expand_env(line);
	}
	else
	{
		buf = NULL;
		if (len)
			expanded = calloc_erx(len + 1, 1);
		else
			expanded = NULL;
	}
	return (copy_buf(expanded, buf, &len));
}

static char	*copy_buf(char *expanded, char *buf, size_t *len)
{
	size_t	len_buf;

	if (expanded)
	{
		len_buf = ft_strlen(buf);
		ft_memcpy(expanded + (*len - len_buf), buf, len_buf);
		*len -= len_buf;
		free(buf);
	}
	return (expanded);
}

static t_bool	is_limiter(char *line, char *limiter)
{
	return (ft_strncmp(line, limiter, ft_strlen(line)) == 0
		|| (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(limiter)));
}
