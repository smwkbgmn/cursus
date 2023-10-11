/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:24:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(char *line, t_list **l_token)
{
	t_token			*token;
	t_lexer			data;

	ft_memset(&data, 0, sizeof(t_lexer));
	token = tokenize(&line, "\n\t \0", &data);
	if (token)
	{
		if (data.wildcard)
			token->type = ASTR;
		ft_lstadd_back(l_token, ft_lstnew(token));
		lexer(line, l_token);
	}
}

t_token	*tokenize(char **line, char *delim, t_lexer *data)
{
	t_token				*token;

	if (**line)
	{
		data->q_sgl ^= (**line == QTE_SGL) && (data->q_dbl == FALSE);
		data->q_dbl ^= (**line == QTE_DBL) && (data->q_sgl == FALSE);
		if (data->q_sgl || data->q_dbl
			|| (!get_metachar(*line) && !hit_delimit(**line, delim)))
			token = proceed_none_meta(line, delim, data);
		else if (data->len == 0)
			token = proceed_zerolen(line, delim, data);
		else
		{
			token = calloc_erx(1, sizeof(t_token));
			token->str = calloc_erx(data->len + 1, 1);
		}
	}
	else
		token = NULL;
	return (token);
}

t_meta	get_metachar(char *str)
{
	int	value;

	if (*str == AMPRSND || *str == PIPE
		|| *str == RD_IN || *str == RD_OUT)
	{
		value = (*str << 8) + *(str + 1);
		if (value == AND || value == OR
			|| value == RD_IN_HRDC || value == RD_OUT_APND)
			return (value);
		else if (*str != AMPRSND)
			return (*str);
	}
	return (NONE);
}

t_bool	hit_delimit(char c, char *delim)
{
	if (*delim)
	{
		if (c == *delim || c == '\0')
			return (TRUE);
		else
			return (hit_delimit(c, delim + 1));
	}
	else
		return (FALSE);
}
