/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:38:43 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 16:54:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "pipex.h"

static t_bool	is_heredoc(char *av_heredoc);

void	init_heredoc(t_data *input, char *av_heredoc, char *av_limiter)
{
	if (is_heredoc(av_heredoc))
	{
		input->heredoc = TRUE;
		write_heredoc(open_fd("heredoc",
				O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644, W), av_limiter);
	}
	else
		input->heredoc = FALSE;
}

static t_bool	is_heredoc(char *av_heredoc)
{
	return (ft_strncmp(av_heredoc, "here_doc", ft_strlen(av_heredoc)) == 0);
}
