/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:26:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 23:17:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

void	init_shell(t_list **l_exe, char *line)
{
	get_execute(l_exe, parse(line));
	printf("check 1\n");
	// free(line);
	dbg_print_procs(*l_exe);
	printf("check 2\n");
}

/*
- unclosed quote, parenthsis
- metachar right after metachar > unreconized metachar
- subsequent redirect apply redirecting in order of appearance
*/
