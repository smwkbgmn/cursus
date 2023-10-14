/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 17:02:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static char		**get_new(char **env, char **av);
static t_bool	search_arg(char *env, char **av);

void	bltin_unset(char **av)
{
	extern char	**environ;

	if (*(av + 1))
		environ = get_new(environ, av + 1);
	g_exit = EXIT_SUCCESS;
}

static char	**get_new(char **env, char **av)
{
	char		**new;
	static int	ac;

	if (*env)
	{
		if (!search_arg(*env, av))
		{
			ac++;
			new = get_new(env + 1, av);
			new[--ac] = try(ft_strdup(*env));
		}
		else
			new = get_new(env + 1, av);
	}
	else
	{
		if (ac)
			new = try(ft_calloc(ac + 1, sizeof(char *)));
		else
			new = NULL;
	}
	return (new);
}

static t_bool	search_arg(char *env, char **av)
{
	if (*av)
	{
		if (ft_strncmp(env, *av, ft_strlen(*av)) == MATCH
			&& *(env + ft_strlen(*av)) == '=')
			return (TRUE);
		else
			return (search_arg(env, av + 1));
	}
	else
		return (FALSE);
}
