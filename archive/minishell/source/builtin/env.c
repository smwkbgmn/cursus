/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 18:09:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "minishell.h"

static void	print(char **env);

void	bltin_env(void)
{
	extern char	**environ;

	print(environ);
	g_exit = EXIT_SUCCESS;
}

static void	print(char **env)
{
	while (*env)
		if (printf("%s\n", *env++) < 0)
			exit_error("printf");
}
