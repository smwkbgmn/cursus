/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:26:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 17:19:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_bool	unclosed_quote(char *line);

void	init_shell(t_list **l_exe, char *line)
{
	if (line)
	{
		if (!unclosed_quote(line))
		{
			add_history(line);
			get_execute(l_exe, parse(line));
		}
	}
	else
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
}

static t_bool	unclosed_quote(char *line)
{
	t_lexer	data;
	t_bool	result;

	ft_memset(&data, 0, sizeof(t_lexer));
	while (*line)
	{
		switch_quote(*line, &data);
		line++;
	}
	result = (data.q_sgl || data.q_dbl);
	if (result)
		set_error(NULL, "unclosed quote is detected", 258);
	return (result);
}
