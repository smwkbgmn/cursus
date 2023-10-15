/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 12:23:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_bool	valid_token(t_list *l_token);
static void		free_token(t_list *l_token);

t_list	*parse(char *line)
{
	t_list	*l_token;

	l_token = NULL;
	lexer(line, &l_token);
	if (l_token)
	{
		expand_wildcard(l_token);
		// dbg_print_token(l_token);
		if (!valid_token(l_token))
		{
			write_errmsg("minishell: syntax error\n");
			free_token(l_token);
			l_token = NULL;
			g_exit = 258;
		}
	}
	free(line);
	return (l_token);
}

static t_bool	valid_token(t_list *l_token)
{
	if (is_redirect(l_token) && !l_token->next)
		return (FALSE);
	if (ref_type(l_token) != NONE && !is_redirect(l_token))
		return (FALSE);
	l_token = l_token->next;
	while (l_token && ref_type(l_token) == NONE)
		l_token = l_token->next;
	if (l_token)
	{
		if (l_token->next)
			return (valid_token(l_token->next));
		else
			return (FALSE);
	}
	else
		return (TRUE);
}

static void	free_token(t_list *l_token)
{
	t_list	*del;

	if (l_token)
	{
		del = l_token;
		l_token = del->next;
		free(((t_token *)del->content)->str);
		ft_lstdelone(del, &free);
		free_token(l_token);
	}
}

t_list	*list_metachar(t_list *l_token, t_meta name)
{
	if (!l_token || ((t_token *)l_token->content)->type == name)
		return (l_token);
	else
		return (list_metachar(l_token->next, name));
}
