/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:36:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 14:45:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>

#include "minishell.h"

void	init_terminal(void)
{
	struct termios	termi;

	if (tcgetattr(STDIN_FILENO, &termi) == ERROR)
		exit(EXIT_FAILURE);
	termi.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termi) == ERROR
		|| tgetent (NULL, "xterm-256color") == ERROR)
		exit(EXIT_FAILURE);
}
