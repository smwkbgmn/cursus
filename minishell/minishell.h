/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:19 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/03 02:40:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#endif

/*
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

- Handle ' (single quote) which should prevent the shell from interpreting
the meta-characters in the quoted sequence.

- Handle " (double quote) which should prevent the shell from interpreting
the mate-characters in the quoted sequence except for $ (dollor sign).

- Implement redirections
	< should redirect input.
	> should redirect output.
	<< should be given a delimiter, then read the input until a line
	contaning the delimiter is seen. However, it doesn't have to update the
	history.

- Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.

- Handle environment variables ($ followed by a sequencce of characters) which
should expand o their values.

- Handlee $? which should expand to the exit status of the most recently
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
But that doesn't mean your own code, yes the code you wrote, can have memory leaks.

(You should limit yourself to the subject description. Anything that is not asked is not required.
If you have any doubt about a requirement, take bash as a reference.)

--- BONUS PART ---
- && and || with parenthesis for priorities.
- Wildcards * should work for the current working directory.
*/