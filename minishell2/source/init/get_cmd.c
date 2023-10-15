/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 15:07:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

t_exe	*init_exe(int argc, t_bool *rd_fail);
void	assign_av(t_exe *exe, int argc, t_list *l_token, t_bool rd_fail);

t_exe	*get_command(t_list *l_token)
{
	static int		argc;
	t_exe			*exe;
	static t_bool	rd_fail;
	t_exe			tmp_rd;

	if (!l_token || is_sequence(l_token))
		exe = init_exe(argc, &rd_fail);
	else
	{
		if (ref_type(l_token) == NONE)
		{
			argc++;
			exe = get_command(l_token->next);
			assign_av(exe, --argc, l_token, rd_fail);
		}
		else
		{
			ft_memset(&tmp_rd, 0, sizeof(t_exe));
			assign_rd(&tmp_rd, ref_type(l_token),
				((t_token *)l_token->next->content)->str, &rd_fail);
			exe = get_command(l_token->next->next);
			apply_rd(exe, &tmp_rd);
		}
	}
	return (exe);
}

t_exe	*init_exe(int argc, t_bool *rd_fail)
{
	t_exe	*exe;

	exe = try(ft_calloc(1, sizeof(t_exe)));
	if (argc)
		exe->cmd.av = try(ft_calloc(argc + 1, sizeof(char *)));
	*rd_fail = FALSE;
	return (exe);
}

void	assign_av(t_exe *exe, int argc, t_list *l_token, t_bool rd_fail)
{
	char	**path;
	char	*env;

	(void)rd_fail;
	exe->cmd.av[argc] = ((t_token *)l_token->content)->str;
	if (argc == 0)
	{
		env = getenv("PATH");
		if (env)
		{
			path = ft_split(env, ':');
			exe->cmd.path = get_path(path, ((t_token *)l_token->content)->str);
			free_path(path);
		}
		else if (is_builtin(((t_token *)l_token->content)->str))
			exe->cmd.path = try(ft_strdup(((t_token *)l_token->content)->str));
	}
}
