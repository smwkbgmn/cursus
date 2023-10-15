/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:10:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 05:40:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static char		*expand_env(char *line);
static char		*copy_buf(char *expanded, char *buf, size_t *len);
static t_bool	is_limiter(char *line, char *limiter);

int	get_heredoc(char *fname, char *delim)
{
	fork_heredoc(fname, delim);
	if (g_exit == SUCCESS)
		return (open_fd(fname, O_RDONLY, 0));
	else
		return (ERROR);
}

void	write_heredoc(int fd_heredoc, char *limiter)
{
	char	*line;
	char	*expanded;

	line = readline("> ");
	if (line)
	{
		if (*line)
		{
			expanded = expand_env(line);
			free(line);
			line = expanded;
		}
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
			buf = try(ft_calloc(2, 1));
			*buf = *line++;
		}
		len += ft_strlen(buf);
		expanded = expand_env(line);
	}
	else
	{
		buf = NULL;
		if (len)
			expanded = try(ft_calloc(len + 1, 1));
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
	return ((*line) && ((ft_strncmp(line, limiter, ft_strlen(line)) == 0
				|| (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
					&& ft_strlen(line) - 1 == ft_strlen(limiter)))));
}
