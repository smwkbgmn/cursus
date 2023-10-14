/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:05:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 06:04:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"

int	pwd(void)
{
	static char	*buf;

	buf = getcwd(buf, 0);
	if (!buf)
		exit_error("getcwd");
	printf("%s\n", buf);
	// ft_putstr_fd(buf, STDIN_FILENO);
	// ft_putstr_fd("\n", STDIN_FILENO);
	free(buf);
	return (EXIT_SUCCESS);
}
