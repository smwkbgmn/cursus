/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_rd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:02:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:18:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "minishell.h"

static void	close_temp_rd(t_exe *tmp);

void	assign_rd(t_exe *exe, t_meta type, char *value, t_bool *rd_fail)
{
	if (!(*rd_fail))
	{
		if (type == RD_IN)
			exe->cmd.fd_rd[R] = open_fd(value, O_RDONLY, 0);
		else if (type == RD_IN_HRDC)
		{
			exe->cmd.fname_heredoc = ft_itoa_ulong_base((unsigned long)value,
					"0123456789ABCDEF");
			exe->cmd.fd_rd[R] = get_heredoc(exe->cmd.fname_heredoc, value);
		}
		else if (type == RD_OUT)
			exe->cmd.fd_rd[W] = open_fd(value,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (type == RD_OUT_APND)
			exe->cmd.fd_rd[W] = open_fd(value,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (exe->cmd.fd_rd[R] == ERROR || exe->cmd.fd_rd[W] == ERROR)
			*rd_fail = TRUE;
	}
}

void	apply_rd(t_exe *exe, t_exe *tmp)
{
	if (exe)
	{
		if (!exe->cmd.fd_rd[R] && tmp->cmd.fd_rd[R])
		{
			exe->cmd.fd_rd[R] = tmp->cmd.fd_rd[R];
			if (tmp->cmd.fname_heredoc)
				exe->cmd.fname_heredoc = tmp->cmd.fname_heredoc;
		}
		else if (tmp->cmd.fd_rd[R])
		{
			close_fd(tmp->cmd.fd_rd[R]);
			if (tmp->cmd.fname_heredoc)
				unlink(tmp->cmd.fname_heredoc);
		}
		if (!exe->cmd.fd_rd[W] && tmp->cmd.fd_rd[W])
			exe->cmd.fd_rd[W] = tmp->cmd.fd_rd[W];
		else if (tmp->cmd.fd_rd[W])
			close_fd(tmp->cmd.fd_rd[W]);
	}
	else
		close_temp_rd(tmp);
}

static void	close_temp_rd(t_exe *tmp)
{
	if (tmp->cmd.fd_rd[R] > 0)
	{
		close_fd(tmp->cmd.fd_rd[R]);
		if (tmp->cmd.fname_heredoc)
			unlink(tmp->cmd.fname_heredoc);
	}
	if (tmp->cmd.fd_rd[W] > 0)
		close_fd(tmp->cmd.fd_rd[W]);
}
