/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:55:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 05:43:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_bool	is_hide(char *name);
static t_bool	does_match_pattern(char *name, char *pattern);
static char		*get_needle(char *pattern, char **p_astr);
static char		*search(char *name, char *pattern, char *needle);

char	**list_files(DIR *p_dir, char *pattern)
{
	static int	count;
	char		**files;
	t_dir		*dir;

	dir = readdir(p_dir);
	if (dir)
	{
		if (!is_hide(dir->d_name)
			&& does_match_pattern(dir->d_name, pattern))
		{
			count++;
			files = list_files(p_dir, pattern);
			files[--count] = try(ft_strdup(dir->d_name));
		}
		else
			files = list_files(p_dir, pattern);
	}
	else
	{
		if (count > 0)
			files = try(ft_calloc(count + 1, sizeof(char *)));
		else
			files = NULL;
	}
	return (files);
}

static t_bool	is_hide(char *name)
{
	return (ft_memcmp(name, ".", 1) == 0);
}

static t_bool	does_match_pattern(char *name, char *pattern)
{
	char	*p_astr;
	char	*needle;

	needle = get_needle(pattern, &p_astr);
	if (needle)
	{
		name = search(name, pattern, needle);
		free(needle);
		if (!name)
			return (FALSE);
		else if (p_astr)
			return (does_match_pattern(name, p_astr));
	}
	return (TRUE);
}

static char	*get_needle(char *pattern, char **p_astr)
{
	if (*pattern == ASTR)
		return (get_needle(pattern + 1, p_astr));
	else
	{
		*p_astr = ft_strchr(pattern, ASTR);
		if (*p_astr)
			return (ft_strdup_ptr(pattern, *p_astr));
		else if (*pattern)
			return (try(ft_strdup(pattern)));
		else
			return (NULL);
	}
}

static char	*search(char *name, char *pattern, char *needle)
{
	if (*pattern == ASTR)
		name = ft_strnstr(name, needle, ft_strlen(name));
	else
		name = ft_strnstr(name, needle, ft_strlen(needle));
	return (name + (ft_strlen(needle) * (name != NULL)));
}
