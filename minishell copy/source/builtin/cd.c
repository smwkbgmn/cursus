/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:17:27 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 01:07:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>

#include "minishell.h"

static char		*assign_curnt_dir(int *exit);
static t_bool	is_dir(char *av, int *exit);
static void		set_env(char *path_cwd, char *path_cd);

void	bltin_cd(char **av)
{
	extern char	**environ;
	char		*path_cd;
	char		*path_cwd;
	int			exit;

	exit = EXIT_SUCCESS;
	if (is_dir(*(av + 1), &exit))
	{
		path_cwd = assign_curnt_dir(&exit);
		path_cd = *(av + 1);
		if (chdir(path_cd) == ERROR)
		{
			write_errmsg("minishell: ");
			perror("cd");
			exit = EXIT_FAILURE;
		}
		else
		{
			path_cd = assign_curnt_dir(&exit);
			set_env(path_cwd, path_cd);
			ft_free(path_cd);
		}
		ft_free(path_cwd);
	}
	g_exit = exit;
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
		*exit = EXIT_FAILURE;
	}
	return (buf);
}

static t_bool	is_dir(char *av, int *exit)
{
	t_stat	buf;

	if (av)
	{
		if (stat(av, &buf) == ERROR)
		{
			write_errmsg("minishell: ");
			perror("cd");
			*exit = EXIT_FAILURE;
		}
		return (S_ISDIR(buf.st_mode));
	}
	else
		return (FALSE);
}

static void	set_env(char *path_cwd, char *path_cd)
{
	char	**av;

	av = try(ft_calloc(3, sizeof(char *)));
	if (path_cd)
	{
		*(av + 1) = try(ft_strjoin("PWD=", path_cd));
		bltin_export(av);
		ft_free(*(av + 1));
	}
	if (path_cwd)
	{
		*(av + 1) = try(ft_strjoin("OLDPWD=", path_cwd));
		bltin_export(av);
		ft_free(*(av + 1));
	}
	ft_free(av);
}
