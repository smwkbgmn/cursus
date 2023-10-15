/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 01:34:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static char	**get_new(char **env, char **av);
static char	**proceed(char **env, char **av, int *ac, t_list **exist);
static char	*add_if_exist(char **env, char **av, t_list **exist);

void	bltin_export(char **av)
{
	extern char	**environ;

	if (*(av + 1))
		environ = get_new(environ, av + 1);
	g_exit = exit;
}

static char	**get_new(char **env, char **av)
{
	static t_list	*exist;
	char			**new;
	static int		ac;

	if (*env || *av)
	{
		new = proceed(env, av, &ac, &exist);
		if (ac == 0)
			ft_lstclear(&exist, NULL);
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

static char	**proceed(char **env, char **av, int *ac, t_list **exist)
{
	char	**new;
	char	*av_exist;

	if (*env)
	{
		(*ac)++;
		av_exist = add_if_exist(env, av, exist);
		new = get_new(env + 1, av);
		if (av_exist)
			new[--(*ac)] = try(ft_strdup(av_exist));
		else
			new[--(*ac)] = try(ft_strdup(*env));
	}
	else
	{
		if (valid(*av) && !is_already_exist(*av, *exist))
		{
			(*ac)++;
			new = get_new(env, av + 1);
			new[--(*ac)] = try(ft_strdup(*av));
		}
		else
			new = get_new(env, av + 1);
	}
	return (new);
}

static char	*add_if_exist(char **env, char **av, t_list **exist)
{
	char	*arg;

	arg = get_exist(*env, av);
	if (arg)
		ft_lstadd_back(exist, try(ft_lstnew(arg)));
	return (arg);
}
