/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 17:10:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse(char *line)
{
	t_list	*l_token;

	l_token = NULL;
	lexer(line, &l_token);
	// dbg_print_token(*l_token);
	expand_wildcard(l_token);
	dbg_print_token(l_token);
	return (l_token);
}

t_list	*list_metachar(t_list *l_token, t_meta name)
{
	if (!l_token || ((t_token *)l_token->content)->type == name)
		return (l_token);
	else
		return (list_metachar(l_token->next, name));
}
