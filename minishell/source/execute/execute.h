/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:32:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/07 23:58:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include  <unistd.h>

# define R 0
# define W 1

typedef struct s_command	t_command;
typedef struct s_process	t_process;
// typedef struct s_execute	t_execute;

void		execute(t_btree *exe);

t_btree		*get_command(t_list *l_token);

int			get_heredoc(char *tmpfile, char *delim);

struct s_command
{
	char	*name;
	char	**av;
	int		rd_in;
	int		rd_out;
	char	*file_heredoc;
};

struct s_process
{
	pid_t		id;
	int			fd[2];
	t_command	cmd;
};

// struct s_execute
// {
// 	t_list	*l_token;
// 	t_list	*l_procs;
// };

#endif