/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_none_meta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:36:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 00:48:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_bool	is_quote(char c, t_bool qte_sgl, t_bool qte_dbl);
static t_token	*copy_buf(t_token *token, t_lexer *data, char *buf);

t_token	*proceed_none_meta(char **line, char *delim, t_lexer *data)
{
	t_token	*token;
	char	*buf;

	if (**line == DOLR && !data->q_sgl)
		buf = expand_env_var(line);
	else
	{
		if (!is_quote(**line, data->q_sgl, data->q_dbl))
		{
			if (**line == '*')
				data->wildcard = TRUE;
			buf = calloc_erx(2, 1);
			*buf = **line;
		}
		else
			buf = NULL;
		(*line)++;
	}
	data->len += ft_strlen(buf);
	token = tokenize(line, delim, data);
	return (copy_buf(token, data, buf));
}

static t_bool	is_quote(char c, t_bool qte_sgl, t_bool qte_dbl)
{
	return ((c == QTE_SGL && !qte_dbl)
		|| (c == QTE_DBL && !qte_sgl));
}

static t_token	*copy_buf(t_token *token, t_lexer *data, char *buf)
{
	size_t	len_buf;

	if (buf && token)
	{
		len_buf = ft_strlen(buf);
		ft_memcpy(token->str + (data->len - len_buf), buf, len_buf);
		data->len -= len_buf;
		free(buf);
	}
	return (token);
}
