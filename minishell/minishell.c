/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/04 18:36:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Read line form STDIN
	1-1. Heredoc mode (Wherever if the Heredoc is, it has to do
	Heredoc first. If there is more than one Heredoc, do first
	one that first meet in the line.)
	1-2. Should be acceptable control input [Ctrl + C, D, \]
2. Parse
	2-1. AND, OR sign with parenthesis [&&, ||, ()]
	2-2. Pipe [|]
	2-3. Dollor sign (means need to invoke the env or exit status)
	2-4. Wildcard [*]
3. Execute entered command
	3-1. If there is AND, OR, do *whole commad line as many as
	the count of logical expressions.
	3-2. If there is pipe, redirect prior STD_OUT to
	following command's STD_IN
	* whole commadn : one full command that or commands that
	connected with pipes.
4. Send the signals
	4-1. While the shell doing things, the main should be available to do
	signaling to any process made from the shell.
*/

// Print MINISHELL$.
// Read line.
// Parse.
// Split to WHOLE COMMAND as many as the count of logical expression
// Put these WHOLE COMMANDs to pipex following the result of prior
// command.

#include <unistd.h>

#include "minishell.h"

void	write_shell(void);

int	main(void)
{
	t_command	**ary_cmds;

	while (LOOP)
	{
		write_shell();
		ary_cmds = parse(get_next_line(STDIN_FILENO));
	}
	return (0);
}

void	write_shell(void)
{
	write(STDIN_FILENO, "god-damn$", 10);
}
