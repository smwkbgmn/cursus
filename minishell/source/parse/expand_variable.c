/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/17 12:52:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse.h"

void	set_value(t_list *l_token);

void	expand_env_var(t_list *l_token)
{
	l_token = list_metachar(l_token, DOLR);
	if (l_token)
	{
		set_value(l_token);
		ft_lstdel_idx(&l_token, 1, &free);
		expand_env_var(l_token->next);
	}
}

void	set_value(t_list *l_token)
{
	t_token	*token;
	char	*value;

	token = l_token->content;
	free(token->str);
	value = getenv(((t_token *)l_token->next->content)->str);
	if (value)
		token ->str = ft_strdup(value);
	else
		token->str = ft_strdup("");
}

// void	set_value(t_list *l_token);

// void	expand_env_var(t_list *l_token)
// {
// 	l_token = list_metachar(l_token, DOLR);
// 	if (l_token)
// 	{
// 		set_value(l_token);
// 		expand_env_var(l_token->next);
// 	}
// }

// void	set_value(t_list *l_token)
// {
// 	char	*value;
// 	t_token	*token;

// 	token = l_token->content;
// 	printf("\nenv : original value : %s\n", token->str);
// 	value = getenv(token->str + 1);
// 	free(token->str);
// 	if (value)
// 		token->str = value;
// 	else
// 		token->str = ft_strdup("");
// 	printf("env : expanded value : %s\n", token->str);
// }
