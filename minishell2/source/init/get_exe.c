/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:25:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 18:34:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_list	*remove_token_used(t_list *l_token);

void	get_execute(t_list **l_exe, t_list *l_token)
{
	t_exe	*exe;

	if (l_token)
	{
		exe = get_command(l_token);
		if (exe)
		{
			ft_lstadd_back(l_exe, ft_lstnew(exe));
			l_token = remove_token_used(l_token);
			if (l_token)
				exe->op_seq = ref_type(l_token);
			else
				exe->op_seq = NONE;
		}
		if (l_token)
			get_execute(l_exe, l_token->next);
	}
}

static t_list	*remove_token_used(t_list *l_token)
{
	t_list	*del;

	if (l_token && !is_sequence(l_token))
	{
		del = l_token;
		if (is_redirect(l_token))
		{
			ft_free(((t_token *)l_token->content)->str);
			if (l_token->next && !is_redirect(l_token->next))
				ft_free(((t_token *)l_token->next->content)->str);
		}
		l_token = remove_token_used(l_token->next);
		ft_lstdelone(del, &free);
	}
	return (l_token);
}
