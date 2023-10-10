/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 12:57:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "source/parse/parse.h"
# include "source/execute/execute.h"

# define SUCCESS 0
# define ERROR -1
# define LOOP 1

extern int	g_errno;

/***** SYSTEM *****/
// init.c
void	init_shell(t_list **exe, char *line);
// error.c
void	*errex(void *ptr);
void	exit_with_error(char *msg);
// files.c
int		open_fd(char *name, int option, int permit);
void	close_fd(int fd);
void	redirect(int fd_to_copy, int fd_to_be);

/* DEBUG */
# include <stdio.h>

void	dbg_print_token(t_list *tokens);
void	dbg_print_procs(t_list *l_procs);

#endif

/********************************* SUBJECT ************************************

--- External functions ---
readline
	rl_clear_history
	rl_on_new_line
	rl_replace_line
	rl_redisplay
	add_history
	
printf

malloc
free
open
read
close
unlink

pipe
dup
dup2

fork
wait
waitpid
wait3
wait4
exit

execve
access

kill
signal
sigaction
sigemptyset
sigaddset

getcwd	: get copy working directory

opendir
readdir
closedir
chdir

stat	: display file status
lstat
fstat

strerror
perror

isatty
ttyname
ttyslot
ioctl

getenv

tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs

--- MANDATORY ---
- Display a prompt when waiting for a new cmmand.

- Have a working history

- Search and launch the right executable (based on the PATH
variable or using relative or an absolute path).

- Avoid using more than one global variable to indicate a received signal.
Consider the implicatins: this approach ensures that your
signal handler will not access your main data structures.
(Be carefull. This global variable cannot provide any other information
or data access than the number of a received signal.
Therefore it is forbidden to use "norm" type structures in global.)

- Not interpret unclosed quotes or special chracters which are not required
by the subject such as \ (backslash) or ; (semicolon)
: PARSING

- Handle ' (single quote) which should prevent the shell from interpreting
the meta-characters in the quoted sequence.
: PARSING

- Handle " (double quote) which should prevent the shell from interpreting
the mate-characters in the quoted sequence except for $ (dollor sign).
: PARSING

- Implement redirections
	< should redirect input.
	> should redirect output.
	<< should be given a delimiter, then read the input until a line
	contaning the delimiter is seen. However, it doesn't have to update the
	history.
: USE THE PIPEX I MADE

- Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
: USE THE PIPEX I MADE

- Handle environment variables ($ followed by a sequencce of characters) which
should expand to their values.

- Handle $? which should expand to the exit status of the most recently
executed foreground pipeline.

- Handle CTRL-C, CTRL-D and CTRL-\ which should behave like in bash.

- In interactive mode:
	CTRL-C displays a new prompt on a new line.
	CTRL-D exits the shell.
	CTRL-\ does nothing.

- Your shell must implement the following builtins
	ECHO with option -n
	CD with only a relative or absolute path
	PWD with no options
	EXPORT with no options
	UNSET with no optons
	ENV with no options or arguments
	EXIT with no options

- The readline() function can cause memory leaks. you don't have to fix them.
But that doesn't mean your own code, yes the code you wrote,
can have memory leaks.

(You should limit yourself to the subject description.
Anything that is not asked is not required. If you have any doubt
about a requirement, take bash as a reference.)

--- BONUS ---
- && and || with parenthesis '(', ')' for priorities.
: UNLIKE PIPE, IT JUST EXECUTES THE COMMANDS LISTED IN THE LINE.
BUT ONLY WHEN THE EXIT_STATUS OF PRIOR COMMAND CAN NOT DETERMINE
WHETHER THIS LOGICAL EXPRESSION IS TRUE OR NOT.

- Wildcards * should work for the current working directory.
: WILDCARD GIVES SOME ARGUMENTS THAT MATCH WITH THE EXPRESSION
TO FOLLOWING COMMNAD. I GUESS AFTER LISTING FILES IN CURRENT DIRECTORY,
I CAN USE THIS LIST AS A WAY FOR GETTING THE ADDTIONAL ARGUMENTS.

******************************************************************************/