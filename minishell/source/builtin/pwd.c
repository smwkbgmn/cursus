/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:05:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 14:27:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "minishell.h"

void	bltin_pwd(void)
{
	static char	*buf;

	buf = getcwd(buf, 0);
	if (!buf)
		exit_error("getcwd");
	printf("%s\n", buf);
	ft_free_set_null((void *)&buf);
	g_exit = EXIT_SUCCESS;
}
