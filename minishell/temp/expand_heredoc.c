/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:50:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 15:14:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "parse.h"

void	expand_heredoc(t_list *tokens)
{
	int	fd;

	tokens = list_token(tokens, HRDC);
	if (tokens)
	{
		fd = open_fd("heredoc",
				O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644, W);
		write_heredoc(fd, ((t_token *)tokens->next->content)->str);
		close_fd(fd);
		expand_heredoc(tokens->next);
	}
}
