/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/19 16:54:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*ft_strtok(char **line, char *delim);
t_token	*proceed_none_meta(char **line, char *delim, t_tokenize *data);
t_token	*proceed_zerolen(char **line, char *delim);

t_list	*lexer(char *line)
{
	static t_list	*l_token;
	t_token			*token;

	token = ft_strtok(&line, "\n\t \0");
	if (token)
	{
		ft_lstadd_back(&l_token, ft_lstnew(token));
		lexer(line);
	}
	return (l_token);
}

t_token	*ft_strtok(char **line, char *delim)
{
	static t_tokenize	data;
	t_token				*token;

	if (**line)
	{
		data.q_sgl ^= (**line == QTE_SGL) && (data.q_dbl == FALSE);
		data.q_dbl ^= (**line == QTE_DBL) && (data.q_sgl == FALSE);
		if (data.q_sgl || data.q_dbl
			|| (!get_metachar(*line) && !hit_delimit(**line, delim)))
			token = proceed_none_meta(line, delim, &data);
		else if (data.len == 0)
			token = proceed_zerolen(line, delim);
		else
		{
			token = ft_calloc(1, sizeof(t_token));
			token->str = ft_calloc(data.len + 1, 1);
		}
	}
	else
		token = NULL;
	return (token);
}

t_token	*proceed_none_meta(char **line, char *delim, t_tokenize *data)
{
	t_token	*token;
	char	buf;
	t_bool	wildcard;

	wildcard = FALSE;
	if (is_literal(**line, data->q_sgl, data->q_dbl))
	{
		if (**line == '*' && !data->q_sgl && !data->q_dbl)
			wildcard = TRUE;
		buf = **line;
		data->len++;
	}
	else
		buf = '\0';
	(*line)++;
	token = ft_strtok(line, delim);
	if (buf)
	{
		token->str[data->len - 1] = buf;
		if (wildcard)
			token->type = ASTR;
		data->len -= 1 * (data->len != 0);
	}
	return (token);
}

t_token	*proceed_zerolen(char **line, char *delim)
{
	t_token	*token;

	if (hit_delimit(**line, delim))
	{
		if (**line == '\n' || **line == '\0')
			return (NULL);
		else
		{
			(*line)++;
			token = ft_strtok(line, delim);
		}
	}
	else
	{
		token = ft_calloc(1, sizeof(t_token));
		token->str = ft_calloc(3, 1);
		token->str[0] = **line;
		if (get_metachar(*line) > 255)
		{
			token->str[1] = *(*line + 1);
			++(*line);
		}
		++(*line);
	}
	return (token);
}
