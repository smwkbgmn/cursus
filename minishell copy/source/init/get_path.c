/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:27:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 18:03:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_name(char **path, char *av_cmd);

char	*get_path(char **path, char *av_cmd)
{
	char	*name;

	if (*av_cmd == '.' || ft_strchr(av_cmd, '/'))
	{
		if (access(av_cmd, X_OK) == SUCCESS)
			name = try(ft_strdup(av_cmd));
		else
		{
			write_errmsg("minishell: ");
			perror("access");
			name = try(ft_strdup("err_cmd"));
		}
	}
	else if (is_builtin(av_cmd))
		name = try(ft_strdup(av_cmd));
	else
		name = find_name(path, try(ft_strjoin("/", av_cmd)));
	return (name);
}

static char	*find_name(char **path, char *av_cmd)
{
	static char	*name;

	if (*path)
	{
		name = ft_strjoin(*path, av_cmd);
		if (access(name, X_OK) != SUCCESS)
		{
			ft_free_set_null((void *)&name);
			find_name(path + 1, av_cmd);
		}
		else
			ft_free(av_cmd);
	}
	else
		ft_free(av_cmd);
	return (name);
}
