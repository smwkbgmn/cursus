/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:16:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/10 20:27:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define R 0
# define W 1

# include <unistd.h>
# include <dirent.h>

typedef enum e_metachar		t_meta;

typedef struct dirent		t_dir;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;

typedef struct s_command	t_cmd;
typedef struct s_execute	t_exe;

/* TOKEN */
t_list	*parse(char *line);
t_list	*list_metachar(t_list *l_token, t_meta name);

void	lexer(char *line, t_list **l_token);
t_token	*tokenize(char **line, char *delim, t_lexer *data);
t_bool	hit_delimit(char c, char *delim);
t_meta	get_metachar(char *str);

t_token	*proceed_none_meta(char **line, char *delim, t_lexer *data);

t_token	*proceed_zerolen(char **line, char *delim, t_lexer *data);

char	*expand_env_var(char **line);

void	expand_wildcard(t_list *l_token);
char	**list_files(DIR *p_dir, char *pattern);

/* EXE */
void	get_execute(t_list **l_exe, t_list *l_token);

t_meta	ref_type(t_list *l_token);
t_bool	is_redirect(t_list *l_token);
t_bool	is_prntsis(t_list *l_token);
t_bool	is_sequence(t_list *l_token);

t_exe	*get_command(t_list *l_token);

char	*get_path(char **path, char *av_cmd);

int		get_heredoc(char *tmpfile, char *delim);

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
	char	*str;
	t_meta	type;
};

struct s_command
{
	char	*path;
	char	**av;
	int		fd_rd[2];
	char	*fname_heredoc;
};

struct s_execute
{
	t_cmd	cmd;
	t_meta	op_seq;
};

#endif