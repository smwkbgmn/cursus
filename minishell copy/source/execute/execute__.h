/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:32:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 18:52:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include  <unistd.h>

typedef struct s_process	t_procs;
typedef struct s_execute	t_exe;

// execute.c
void	execute(t_list *l_exe);

// parent.c
void	parent(t_procs *ps, t_list *l_exe, int *fd_prev_out);

// child.c
void	child(t_procs *ps, t_exe *exe, int fd_prev_out);

struct s_process
{
	pid_t		id;
	int			fd_pipe[2];
};

#endif