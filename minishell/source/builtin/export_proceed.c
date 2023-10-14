/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_proceed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:06:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 23:25:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static size_t	get_len_name(char *av);

char	*get_exist(char *env, char **av)
{
	if (*av)
	{
		if (ft_strncmp(env, *av, get_len_name(*av)) == MATCH
			&& *(env + get_len_name(*av)) == '=' && **av != '=')
			return (*av);
		else
			return (get_exist(env, av + 1));
	}
	else
		return (NULL);
}

static size_t	get_len_name(char *av)
{
	size_t	len;

	len = 0;
	while (av[len] != '=' && av[len])
		len++;
	return (len);
}

t_bool	valid(char *arg)
{
	if (ft_isalpha(*arg) || *arg == '_')
	{
		arg++;
		while (*arg && (ft_isalnum(*arg) || *arg == '_'))
			arg++;
		if (*arg != '=' || (*arg && ft_strchr(arg + 1, '=')))
			set_error("export: not a valid identifier", EXIT_FAILURE);
		return (!(*arg) || *arg == '=');
	}
	else
	{
		set_error("export: not a valid identifier", EXIT_FAILURE);
		return (FALSE);
	}
}

t_bool	is_already_exist(char *arg, t_list *exist)
{
	if (exist)
	{
		if (arg == exist->content)
			return (TRUE);
		else
			return (is_already_exist(arg, exist->next));
	}
	else
		return (FALSE);
}
