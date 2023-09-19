/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 00:36:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>

#include "parse.h"

void	expand(t_list *l_token);
char	**list_files(DIR *p_dir, char *phrase, int count);
t_bool	does_match_pattern(char *name, char *pattern);

void	expand_wildcard(t_list *l_token)
{
	l_token = list_metachar(l_token, ASTR);
	if (l_token)
	{
		expand(l_token);
		expand_wildcard(l_token->next);
	}
}

void	expand(t_list *l_token)
{
	char	**files;
	DIR		*p_dir;

	p_dir = opendir(".");
	files = list_files(p_dir,
			((t_token *)l_token->content)->str, 0);
	// if (files)
		// sort by name
	// else
		// set errno and print "no matches found: .*"
	closedir(p_dir);
	while (*files)
		printf("%s\n", *files++);
}

char	**list_files(DIR *p_dir, char *pattern, int count)
{
	char		**files;
	char		*name;
	t_dir		*dir;

	dir = readdir(p_dir);
	if (dir)
	{
		name = ft_strdup(dir->d_name);
		if (!does_match_pattern(name, pattern))
		{
			free(name);
			name = NULL;
		}
		files = list_files(p_dir, pattern, count + (name != NULL));
	}
	else
	{
		name = NULL;
		files = ft_calloc(count, sizeof(char *));
	}
	if (name)
		files[count - 1] = name;
	return (files);
}

t_bool	does_match_pattern(char *name, char *pattern)
{
	char	*needle;
	char	*p_astr;
	size_t	len_needle;

	if (*pattern)
	{
		p_astr = ft_strchr(pattern, '*');
		if (p_astr)
			needle = ft_strdup_ptr(pattern, p_astr);
		else
			needle = ft_strdup(pattern);
		printf("now needle %s\n", needle);
		len_needle = ft_strlen(needle);
		name = ft_strnstr(name, needle, len_needle);
		printf("found ptr %s\n", name);
		free(needle);
		if (name)
			return (does_match_pattern(name + len_needle, p_astr + 1));
		else
			return (FALSE);
	}
	else
		return (TRUE);
}
