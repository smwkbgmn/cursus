/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:09:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 14:55:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static t_bool	is_option(char *arg);
static void		print(char **av);

void	bltin_echo(char **av)
{
	t_bool	option;

	option = FALSE;
	if (*(av + 1))
	{
		option = is_option(*(av + 1));
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

static t_bool	is_option(char *arg)
{
	if (ft_strncmp(arg, "-n", 2) == MATCH)
	{
		arg += 2;
		while (*arg == 'n')
			arg++;
		return (*arg == '\0');
	}
	else
		return (FALSE);
}
