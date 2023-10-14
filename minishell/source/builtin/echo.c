/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:09:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 15:11:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static void	print(char **av);

void	bltin_echo(char **av)
{
	t_bool	option;

	option = FALSE;
	if (*(av + 1))
	{
		if (ft_strncmp(*(av + 1), "-n", 3) == MATCH)
			option = TRUE;
		print(av + 1 + (option));
	}
	if (!option)
		printf("\n");
	g_exit = EXIT_SUCCESS;
}

static void	print(char **av)
{
	while (*av)
	{
		if (printf("%s", *av++) < 0)
			exit_error("printf");
		if (*av)
			printf(" ");
	}
}
