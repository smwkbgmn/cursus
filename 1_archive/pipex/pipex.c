/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:05:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 16:50:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_exit_stat_of_last_cmd(t_data *input);

int	main(int ac, char **av, char **env)
{
	static t_data	input;
	int				exit_stat;

	if (ac > 4)
	{
		init_data(&input, ac, av, env);
		execute(&input);
		exit_stat = get_exit_stat_of_last_cmd(&input);
		free_data(&input);
		return (exit_stat);
	}
	else
		return (0);
}

static int	get_exit_stat_of_last_cmd(t_data *input)
{
	return (input->cmd[input->cnt_cmd - 1].exit_stat);
}
