/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_zerolen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:37:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 17:10:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*assign_str(char **line);

t_token	*proceed_zerolen(char **line, char *delim, t_lexer *data)
{
	t_token	*token;

	if (hit_delimit(**line, delim))
	{
		if (**line == '\n' || **line == '\0')
			return (NULL);
		else
		{
			(*line)++;
			token = tokenize(line, delim, data);
		}
	}
	else
	{
		token = assign_str(line);
		if (get_metachar(*line) > 255)
		{
			token->str[1] = *(*line + 1);
			++(*line);
		}
		++(*line);
		token->type = get_metachar(token->str);
	}
	return (token);
}

static t_token	*assign_str(char **line)
{
	t_token	*token;

	token = try(ft_calloc(1, sizeof(t_token)));
	token->str = try(ft_calloc(3, 1));
	token->str[0] = **line;
	return (token);
}
