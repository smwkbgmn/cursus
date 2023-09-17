/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 20:30:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse.h"

void	set_value(t_list *tokens);

void	expand_env_var(t_list *tokens)
{
	tokens = list_metachar(tokens, DOLR);
	if (tokens)
	{
		set_value(tokens);
		ft_lstdel_idx(&tokens, 1, &free);
		expand_env_var(tokens->next);
	}
}

void	set_value(t_list *tokens)
{
	char	*value;
	t_token	*token;

	token = tokens->content;
	printf("\nenv : original value : %s\n", token->str);
	value = getenv(token->str + 1);
	free(token->str);
	if (value)
		token->str = value;
	else
		token->str = ft_strdup("");
	printf("env : expanded value : %s\n", token->str);
}

// void	set_value(t_list *tokens);

// void	expand_env_var(t_list *tokens)
// {
// 	tokens = list_metachar(tokens, DOLR);
// 	if (tokens)
// 	{
// 		set_value(tokens);
// 		expand_env_var(tokens->next);
// 	}
// }

// void	set_value(t_list *tokens)
// {
// 	char	*value;
// 	t_token	*token;

// 	token = tokens->content;
// 	printf("\nenv : original value : %s\n", token->str);
// 	value = getenv(token->str + 1);
// 	free(token->str);
// 	if (value)
// 		token->str = value;
// 	else
// 		token->str = ft_strdup("");
// 	printf("env : expanded value : %s\n", token->str);
// }
