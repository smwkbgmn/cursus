/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 18:29:04 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static char	*get_name(char **line);
static char	*expand(char *name);

char	*expand_env_var(char **line)
{
	(*line)++;
	if (**line == '?')
	{
		(*line)++;
		return (ft_itoa(g_exit));
	}
	else
		return (expand(get_name(line)));
}

static char	*get_name(char **line)
{
	char			*name;
	char			buf;
	static size_t	len;

	if (ft_isalpha(**line) || **line == '_')
	{
		buf = **line;
		(*line)++;
		len++;
		name = get_name(line);
		name[len-- - 1] = buf;
	}
	else
	{
		if (len == 0)
			name = ft_strdup("$");
		else
			name = calloc_erx(len + 1, 1);
	}
	return (name);
}

static char	*expand(char *name)
{
	char	*value;

	if (*name == DOLR)
		return (name);
	else
	{
		value = getenv(name);
		if (value)
			value = ft_strdup(value);
		else
			value = ft_strdup("");
		return (value);
	}
}
