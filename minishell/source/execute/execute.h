/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:32:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/09 14:34:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include  <unistd.h>

# define R 0
# define W 1

typedef struct s_command	t_command;
typedef struct s_process	t_process;
typedef struct s_execute	t_execute;

int			execute(t_list *exe);

int			parent(t_process *ps, t_list *l_exe);

int			child(t_process *ps, t_execute *exe);

void		get_execute(t_list **exe, t_list *l_token);

t_bool		is_redirect(t_list *l_token);
t_bool		is_prntsis(t_list *l_token);
t_bool		is_sequence(t_list *l_token);

t_execute	*get_command(t_list *l_token);

char		*get_path(char **path, char *av_cmd);

int			get_heredoc(char *tmpfile, char *delim);

struct s_command
{
	char	*path;
	char	**av;
	int		fd_rd[2];
	char	*fname_heredoc;
};

struct s_execute
{
	t_command	cmd;
	t_meta		op_seq;
};

struct s_process
{
	pid_t		id;
	int			fd_pipe[2];
};

#endif