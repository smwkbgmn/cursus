/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:25:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/09 01:58:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

void	get_execute(t_list **l_exe, t_list *l_token)
{
	t_list		*token;
	t_execute	*exe;

	if (l_token)
	{
		token = l_token;
		if (is_prntsis(l_token))
		{	
			exe = ft_calloc(1, sizeof(t_execute));
			exe->op_seq = ((t_token *)token->content)->type;
			ft_lstadd_back(l_exe, ft_lstnew(exe));
			get_execute(l_exe, l_token->next);
			free(((t_token *)token->content)->str);
			ft_lstdelone(l_token, &free);
		}
		else
		{
			exe = get_command(l_token);
			ft_lstadd_back(l_exe, ft_lstnew(exe));
			while (token && ((t_token *)token->content)->type == NONE)
			{
				l_token = l_token->next;
				ft_lstdelone(token, &free);
				token = l_token;
			}
			if (token)
			{
				l_token = l_token->next;
				exe->op_seq = ((t_token *)token->content)->type;
				ft_lstdelone(token, &free);
				get_execute(l_exe, l_token);
			}
			else
				exe->op_seq = NONE;
		}
	}
}

