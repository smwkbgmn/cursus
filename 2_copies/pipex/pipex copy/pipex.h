/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:04:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 03:06:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

# include "libft.h"

# define SUCCESS 0
# define ERROR -1
# define FAIL -1
# define R 0
# define W 1

typedef unsigned int	t_uint;

typedef struct s_cmd
{
	char	*name;
	char	**av;
}	t_cmd;

typedef struct s_data
{
	t_bool	heredoc;
	int		fd_in;
	int		fd_out;
	t_cmd	*cmd;
	int		cnt_cmd;
	char	**env;
	char	**env_path;
}	t_data;

typedef struct s_process
{
	pid_t	pid;
	int		fd[2];
}	t_process;

t_bool	init_data(t_data *input, int ac, char **av, char **env);
void	init_heredoc(t_data *input, char *av_heredoc, char *av_limiter);
void	init_fd(t_data *input, int ac, char **av);
void	init_env(t_data *input, char **env);
void	init_cmd(t_data *input, int ac, char **av);

char	**get_arys_path(char **env);
t_cmd	*get_ary_cmd(char **path, t_uint cnt, char **av);

void	execute(t_data *input);
void	parent(t_data *input, t_process ps, int *i_cmd, int *fd_prev);
void	child(t_data *input, t_process *ps, int i_cmd, int fd_prev);

void	free_data(t_data *input);
void	exit_with_error(char *msg);

int		open_fd(char *name, int option, int permit);
void	close_fd(int fd);
void	redirect(int fd_to_copy, int fd_to_be);

/// debug ///
void	dbg_print_av(char **av);
void	dbg_print_input(t_data *input);


#endif