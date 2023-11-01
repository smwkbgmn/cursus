/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 02:20:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:58:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	static t_list	*l_exe;

	init_terminal();
	while (LOOP)
	{
		init_signal(SHELL);
		init_shell(&l_exe, readline("minishell$ "));
		if (l_exe)
		{
			execute(l_exe);
			free_data(&l_exe);
		}
	}
	return (g_exit);
}
