/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:58:23 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/10 18:42:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_meta	ref_type(t_list *l_token)
{
	return (((t_token *)l_token->content)->type);
}

t_bool	is_redirect(t_list *l_token)
{
	t_meta	type;

	type = ((t_token *)l_token->content)->type;
	return (type == RD_IN || type == RD_OUT
		|| type == RD_IN_HRDC || type == RD_OUT_APND);
}

t_bool	is_sequence(t_list *l_token)
{
	t_meta	type;

	type = ((t_token *)l_token->content)->type;
	return (type == AND || type == OR || type == PIPE);
}

t_bool	is_control(t_list *l_token)
{
	t_meta	type;

	type = ((t_token *)l_token->content)->type;
	return (type == AND || type == OR);
}
