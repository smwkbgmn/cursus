/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:17:27 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:18:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>

#include "minishell.h"

void	bltin_cd(char **av)
{
	char	*home;
	int		exit;

	exit = EXIT_SUCCESS;
	if (*(av + 1))
		cd_path(*(av + 1), &exit);
	else
	{
		home = get_home(NULL, &exit);
		if (home)
			cd_path(home, &exit);
	}
	g_exit = (exit == ERROR);
}

char	*get_home(char *path, int *exit)
{
	char	*home;

	home = getenv("HOME");
	if (home)
	{
		if (path)
			path = try(ft_strjoin(home, path + 1));
		else
			path = home;
	}
	else
	{
		path = NULL;
		write_errmsg("minishell: cd: HOME not set\n");
		*exit = ERROR;
	}
	return (path);
}

t_bool	is_dir(char *av, int *exit)
{
	t_stat	buf;

	if (av)
	{
		if (stat(av, &buf) == ERROR)
		{
			write_errmsg("minishell: ");
			perror(av);
			*exit = ERROR;
		}
		return (S_ISDIR(buf.st_mode));
	}
	else
		return (FALSE);
}
