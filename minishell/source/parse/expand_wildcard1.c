/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 18:03:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	expand(t_list *l_token);
static void	replace_token(t_list *l_token, char **files);
static void	sort_by_name(char **files);
static void	swap(char **files, int lowst, int cmp);

void	expand_wildcard(t_list *l_token)
{
	l_token = list_metachar(l_token, ASTR);
	if (l_token)
	{
		expand(l_token);
		expand_wildcard((l_token)->next);
	}
}

static void	expand(t_list *l_token)
{
	char	**files;
	DIR		*p_dir;

	p_dir = opendir(".");
	files = list_files(p_dir,
			((t_token *)l_token->content)->str, 0);
	if (files)
	{
		sort_by_name(files);
		replace_token(l_token, files);
	}
	else
		((t_token *)l_token->content)->type = NONE;
	closedir(p_dir);
	if (files)
		while (*files)
			printf("%s\n", *files++);
}

static void	replace_token(t_list *l_token, char **files)
{
	int		idx;	
	t_token	*token;

	idx = 0;
	while (files[idx])
	{
		if (idx == 0)
			((t_token *)l_token->content)->str = files[idx];
		else
		{
			token = ft_calloc(1, sizeof(t_token));
			token->str = files[idx];
			ft_lstadd_idx(&l_token, ft_lstnew(token), idx);
		}
		idx++;
	}
}

static void	sort_by_name(char **files)
{
	int	lowst;
	int	cmp;

	lowst = 0;
	while (files[lowst])
	{
		cmp = lowst + 1;
		while (files[cmp])
		{
			if (ft_memcmp(files[lowst], files[cmp],
					ft_strlen(files[lowst])) > 0)
				swap(files, lowst, cmp);
			cmp++;
		}
		lowst++;
	}
}

static void	swap(char **files, int lowst, int cmp)
{
	char	*tmp;

	tmp = files[lowst];
	files[lowst] = files[cmp];
	files[cmp] = tmp;
}
