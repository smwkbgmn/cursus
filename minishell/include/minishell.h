/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 17:15:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "init.h"
# include "execute.h"
# include "builtin.h"

# define SUCCESS 0
# define MATCH 0
# define ERROR -1
# define LOOP 1

int					g_exit;

typedef enum e_mode	t_mode;

// free.c
void	free_data(t_list **l_exe);

// signal.c
void	init_signal(t_mode mode);

// init.c
void	init_shell(t_list **l_exe, char *line);

// error.c
void	*try(void *ptr);
void	set_error(char *av, char *msg, int exit);
void	exit_error(char *msg);
void	exit_error_usr(int status);
void	write_errmsg(char *msg);

// files.c
int		open_fd(char *name, int option, int permit);
void	close_fd(int fd);
void	redirect(int fd_to_copy, int fd_to_be);

// free.c
void	free_data(t_list **l_exe);

// terminal.c
void	init_terminal(void);

enum e_mode
{
	SHELL,
	HEREDOC,
	EXE
};

#endif
