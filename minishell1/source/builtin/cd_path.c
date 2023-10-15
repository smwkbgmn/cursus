/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:10:48 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:17:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static char	*assign_curnt_dir(int *exit);
static void	cd(char *path, int *exit);
static void	set_env(char *cwd, char *path);

void	cd_path(char *path, int *exit)
{
	char	*home;

	if (*path == '~')
		home = get_home(path, exit);
	else
		home = NULL;
	if (home)
	{
		cd(home, exit);
		ft_free(home);
	}
	else if (*exit != ERROR && is_dir(path, exit))
		cd(path, exit);
}

static char	*assign_curnt_dir(int *exit)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 0);
	if (!buf)
	{
		write_errmsg("minishell: ");
		perror("getcwd");
		*exit = ERROR;
	}
	return (buf);
}

static void	cd(char *path, int *exit)
{
	char	*cwd;

	if (ft_strncmp(path, cwd, ft_strlen(path) != MATCH)
		|| ft_strncmp(path, cwd, ft_strlen(cwd)) != MATCH)
	{
		cwd = assign_curnt_dir(exit);
		if (chdir(path) == ERROR)
		{
			write_errmsg("minishell: ");
			perror(path);
			*exit = ERROR;
		}
		else
		path = assign_curnt_dir(exit);
		set_env(cwd, path);
		ft_free(path);
		ft_free(cwd);
	}
}

static void	set_env(char *cwd, char *path)
{
	char	**av;

	av = try(ft_calloc(3, sizeof(char *)));
	if (path)
	{
		*(av + 1) = try(ft_strjoin("PWD=", path));
		bltin_export(av);
		ft_free(*(av + 1));
	}
	if (cwd)
	{
		*(av + 1) = try(ft_strjoin("OLDPWD=", cwd));
		bltin_export(av);
		ft_free(*(av + 1));
	}
	ft_free(av);
}
