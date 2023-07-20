/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:40:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 04:12:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_arys_path(char **env);
static char	*find_path(char **env);

void	init_env(t_data *input, char **env)
{
	input->env = env;
	input->env_path = get_arys_path(env);
	if (!input->env_path)
		exit_with_error("malloc");
}

static char	**get_arys_path(char **env)
{
	char	*path;

	path = find_path(env);
	if (!path)
		exit_with_error("env_path not found");
	return (ft_split(path + 5, ':'));
}

static char	*find_path(char **env)
{
	char	*path;

	path = NULL;
	while (*env && !path)
	{
		path = ft_strnstr(*env, "PATH=", 5);
		env++;
	}
	return (path);
}
