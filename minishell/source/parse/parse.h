/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:16:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/22 13:34:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <dirent.h>

# include "libft.h"

typedef struct dirent	t_dir;

typedef enum e_metachar	t_metachar;

typedef struct s_lexer	t_lexer;
typedef struct s_token	t_token;

t_list		*parse(char *line);

t_list		*list_metachar(t_list *tokens, t_metachar name);

t_list		*lexer(char *line);
t_token		*tokenize(char **line, char *delim, t_lexer *data);
t_bool		hit_delimit(char c, char *delim);
t_metachar	get_metachar(char *str);

t_token		*proceed_none_meta(char **line, char *delim, t_lexer *data);

t_token		*proceed_zerolen(char **line, char *delim, t_lexer *data);

char		*expand_env_var(char **line);

void		expand_wildcard(t_list *l_token);
char		**list_files(DIR *p_dir, char *pattern);
// char		**list_files(DIR *p_dir, char *pattern, int count);

enum e_metachar
{
	NONE,
	AMPRSND = '&',
	AND = 9766,
	PIPE = '|',
	OR = 31868,
	RD_IN = '<',
	RD_IN_HRDC = 15420,
	RD_OUT = '>',
	RD_OUT_APND = 15934,
	DOLR = '$',
	ASTR = '*',
	PRNTSIS_OPN = '(',
	PRNTSIS_CLS = ')',
	QTE_SGL = '\'',
	QTE_DBL = '\"'
};

struct s_lexer
{
	t_bool	wildcard;
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