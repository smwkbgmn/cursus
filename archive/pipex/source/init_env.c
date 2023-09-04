/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:40:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 17:13:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static char	**get_arys_path(char **env);
static char	*find_path(char **env);

void	init_env(t_data *input, char **env)
{
	input->env = env;
	input->path = get_arys_path(env);
}

static char	**get_arys_path(char **env)
{
	char	*env_path;

	env_path = find_path(env);
	if (!env_path)
	{
		write(STDERR_FILENO, "env_path not found\n", 19);
		return (NULL);
	}
	else
		return ((char **)catcher2((void **)ft_split(env_path + 5, ':')));
}

static char	*find_path(char **env)
{
	char	*env_path;

	env_path = NULL;
	while (*env && !env_path)
	{
		env_path = ft_strnstr(*env, "PATH=", 5);
		env++;
	}
	return (env_path);
}
