/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child_chkerror.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:00:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 17:10:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static t_bool	is_cmd_exist(char *name);
static t_bool	is_cmd_error(char *name);
static t_bool	is_fd_in_not_opend(int fd_in, int idx);

void	check_cmd_and_fd(t_data *input, int idx)
{
	if (!is_cmd_exist(input->cmd[idx].name))
	{
		write_command_not_found(*input->cmd[idx].av);
		exit_with_status(NULL, 127);
	}
	else if (is_cmd_error(input->cmd[idx].name))
		exit_with_status(NULL, 126);
	else if (is_fd_in_not_opend(input->fd_in, idx))
		exit_with_status(NULL, EXIT_SUCCESS);
}

static t_bool	is_cmd_exist(char *name)
{
	return (name != NULL);
}

static t_bool	is_cmd_error(char *name)
{
	return (ft_strncmp(name, "null", 4) == 0);
}

static t_bool	is_fd_in_not_opend(int fd_in, int idx)
{
	return (idx == 0 && fd_in == ERROR);
}
