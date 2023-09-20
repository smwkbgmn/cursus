/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:05:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 18:02:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse.h"

t_list	*parse(char *line)
{
	t_list	*l_token;

	// Check unclosed things and errors for parsing.
	// This also used when getting input from heredoc.
	l_token = lexer(line);
	dbg_print_token(l_token);
	expand_env_var(l_token);
	expand_wildcard(l_token);
	dbg_print_token(l_token);
	return (l_token);
}

t_list	*list_metachar(t_list *l_token, t_metachar name)
{
	if (!l_token || ((t_token *)l_token->content)->type == name)
		return (l_token);
	else
		return (list_metachar(l_token->next, name));
}
