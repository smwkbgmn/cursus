/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:25:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/09 19:09:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_list	*remove_used_tokens(t_list *l_token);

// now the rest metacharacters are AND, OR, PIPE, PRNTSIS

void	get_execute(t_btree **b_exe, t_list *l_token)
{
	t_execute	*exe;

	if (l_token)
	{
		exe = get_command(l_token);
		if (exe)
		{
			l_token = remove_used_tokens(l_token);
			if (l_token)
			{
				exe->op_seq = ((t_token *)l_token->content)->type;
				if (group)
				{
					btr_add_l(b_exe, exe);
				}
			}
			else
			{
				exe->op_seq = NONE;
				btr_add_r(b_exe, exe);
			}
		}
		get_execute(b_exe, l_token->next);
	}
}

t_bool	group(t_list *l_token)
{
	return (!(is_sequence(l_token) && !is_prntsis(l_token->next)));
}

// void	get_execute(t_list **l_exe, t_list *l_token)
// {
// 	t_execute	*exe;

// 	if (l_token)
// 	{
// 		exe = get_command(l_token);
// 		if (exe)
// 		{
// 			ft_lstadd_back(l_exe, ft_lstnew(exe));
// 			l_token = remove_used_tokens(l_token);
// 			if (l_token)
// 				exe->op_seq = ((t_token *)l_token->content)->type;
// 			else
// 				exe->op_seq = NONE;
// 		}
// 		else
// 		{
// 			exe = ft_calloc(1, sizeof(t_execute));
// 			exe->op_seq = ((t_token *)l_token->content)->type;
// 			ft_lstadd_back(l_exe, ft_lstnew(exe));
// 		}
// 		if (l_token)
// 			get_execute(l_exe, l_token->next);
// 	}
// }

static t_list	*remove_used_tokens(t_list *l_token)
{
	t_list	*del;

	if (l_token && !is_sequence(l_token) && !is_prntsis(l_token))
	{
		del = l_token;
		if (is_redirect(l_token))
			free(((t_token *)l_token->content)->str);
		l_token = remove_used_tokens(l_token->next);
		ft_lstdelone(del, &free);
	}
	return (l_token);
}
