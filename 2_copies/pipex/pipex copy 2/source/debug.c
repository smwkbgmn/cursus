/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:10:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/20 19:31:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_env(char **env);
void	print_cmds(t_cmd *cmd, int ac);

void	dbg_print_av(char **av)
{
	ft_printf("%s\n", *av);
	if (*(av + 1))
		dbg_print_av(av + 1);
	else
		ft_printf("\n");
}

void	dbg_print_input(t_data *input)
{
	// ft_printf("fd_in : %d\n", input->fd_in);
	// ft_printf("fd_out : %d\n", input->fd_out);
	// print_env(input->env);
	print_cmds(input->cmd, input->cnt_cmd);
}

void	print_env(char **env)
{
	int	ptr;

	ft_printf("environments :\n");
	ptr = 0;
	while (env[ptr])
		ft_printf("%s\n", env[ptr++]);
	ft_printf("\n");
}

void	print_cmds(t_cmd *cmd, int cnt_cmd)
{
	int	ptr;
	int	idx;

	ptr = 0;
	while (ptr < cnt_cmd)
	{
		ft_printf("cmd[%d]\n", ptr);
		ft_printf("\tname : %s\n", cmd[ptr].name);
		ft_printf("\targuments :\n");
		idx = 0;
		while (cmd[ptr].av[idx])
			ft_printf("\t%s\n", cmd[ptr].av[idx++]);
		ft_printf("\n");
		ptr++;
	}
}
