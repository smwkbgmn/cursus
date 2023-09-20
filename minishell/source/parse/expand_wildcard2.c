/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:55:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 18:03:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse.h"

static t_bool	is_directory_dot(char *name, size_t len);
static t_bool	does_match_pattern(char *name, char *pattern);
static char		*get_needle(char *pattern, char **p_astr);
static char		*search(char *name, char *pattern, char *needle);

char	**list_files(DIR *p_dir, char *pattern, int count)
{
	char		**files;
	char		*name;
	t_dir		*dir;

	dir = readdir(p_dir);
	if (dir)
	{
		if (!is_directory_dot(dir->d_name, ft_strlen(dir->d_name))
			&& does_match_pattern(dir->d_name, pattern))
			name = ft_strdup(dir->d_name);
		else
			name = NULL;
		files = list_files(p_dir, pattern, count + (name != NULL));
	}
	else
	{
		name = NULL;
		if (count > 0)
			files = ft_calloc(count + 1, sizeof(char *));
		else
			files = NULL;
	}
	if (name)
		files[count] = name;
	return (files);
}

static t_bool	is_directory_dot(char *name, size_t len)
{
	return (ft_memcmp(name, ".", len) == 0
		|| ft_memcmp(name, "..", len) == 0);
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
	char	*needle;

	if (*pattern == ASTR)
		return (get_needle(pattern + 1, p_astr));
	else
	{
		*p_astr = ft_strchr(pattern, ASTR);
		if (*p_astr)
			needle = ft_strdup_ptr(pattern, *p_astr);
		else if (*pattern)
			needle = ft_strdup(pattern);
		else
			needle = NULL;
		return (needle);
	}
}

static char	*search(char *name, char *pattern, char *needle)
{
	if (*pattern == ASTR)
		return (ft_strnstr(name, needle, ft_strlen(name)));
	else
		return (ft_strnstr(name, needle, ft_strlen(needle)));
}
