/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:16:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/19 17:16:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

typedef struct dirent		t_dir;

typedef enum e_metachar		t_metachar;

typedef struct s_tokenize	t_tokenize;
typedef struct s_token		t_token;

t_list		*parse(char *line);
t_list		*list_metachar(t_list *tokens, t_metachar name);

t_list		*lexer(char *line);
t_list		*list_metachar(t_list *tokens, t_metachar name);

t_metachar	get_metachar(char *str);
t_bool		hit_delimit(char c, char *delim);
t_bool		is_literal(char c, t_bool qte_sgl, t_bool qte_dbl);

void		expand_env_var(t_list *tokens);

void		expand_wildcard(t_list *l_token);

enum e_metachar
{
	NONE,
	AND = 9766,
	OR = 31868,
	HRDC = 15420,
	RDR_OUT_APND = 15934,
	AMPRSND = '&',
	PIPE = '|',
	RDR_IN = '<',
	RDR_OUT = '>',
	DOLR = '$',
	ASTR = '*',
	PRNTSIS_OPN = '(',
	PRNTSIS_CLS = ')',
	QTE_SGL = '\'',
	QTE_DBL = '\"'
};

struct s_tokenize
{
	t_bool	q_sgl;
	t_bool	q_dbl;
	size_t	len;
};

struct s_token
{
	char		*str;
	t_metachar	type;
};

#endif