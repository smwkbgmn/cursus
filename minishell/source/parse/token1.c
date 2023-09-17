/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 19:18:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_strtok(char **line, char *delim);
char	*proceed_none_meta(char **line, char *delim, t_tokenize *data);
char	*proceed_zerolen(char **line, char *delim);

t_list	*lexer(char *line)
{
	char	*str;
	t_token	*token;
	t_list	*tokens;

	while (1)
	{
		str = ft_strtok(&line, "\n\t \0");
		if (str)
		{
			printf("token [%s]\t", str);
			token = ft_calloc(1, sizeof(t_token));
			token->str = str;
			token->type = get_metachar(str);
			printf("[%d]\n", token->type);
			ft_lstadd_back(&tokens, ft_lstnew(token));
		}
		else
			break ;
	}
	return (tokens);
}

char	*ft_strtok(char **line, char *delim)
{
	static t_tokenize	data;
	char				*token;

	data.q_sgl ^= (**line == QTE_SGL) && (data.q_dbl == FALSE);
	data.q_dbl ^= (**line == QTE_DBL) && (data.q_sgl == FALSE);
	if (data.q_sgl || data.q_dbl
		|| (!get_metachar(*line) && !hit_delimit(**line, delim)))
		// || get_metachar(*line) == DOLR || get_metachar(*line) == ASTR
		token = proceed_none_meta(line, delim, &data);
	else if (data.len == 0)
		token = proceed_zerolen(line, delim);
	else
		token = ft_calloc(data.len + 1, 1);
	return (token);
}

char	*proceed_none_meta(char **line, char *delim, t_tokenize *data)
{
	char	*token;
	char	buf;

	if (is_literal(**line, data->q_sgl, data->q_dbl))
	{
		buf = **line;
		data->len++;
	}
	else
		buf = '\0';
	(*line)++;
	token = ft_strtok(line, delim);
	if (buf)
	{
		token[data->len - 1] = buf;
		data->len -= 1 * (data->len != 0);
	}
	return (token);
}

char	*proceed_zerolen(char **line, char *delim)
{
	char	*token;

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
		token = ft_calloc(3, 1);
		token[0] = **line;
		if (get_metachar(*line) > 255)
		{
			token[1] = *(*line + 1);
			++(*line);
		}
		++(*line);
	}
	return (token);
}
