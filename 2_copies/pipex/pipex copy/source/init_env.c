/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:40:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/19 22:25:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **env);

void	init_env(t_data *input, char **env)
{
	input->env = env;
	input->env_path = get_arys_path(env);
}

char	**get_arys_path(char **env)
{
	char	*path;

	path = find_path(env);
	if (path)
		return (ft_split(path + 5, ':'));
	else
		return (NULL);
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
