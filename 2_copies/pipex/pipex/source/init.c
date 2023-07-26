/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:40:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 17:30:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *input, int ac, char **av, char **env)
{
	if (ac > 5)
		init_heredoc(input, *(av + 1), *(av + 2));
	init_file(input, ac, av);
	init_env(input, env);
	init_cmd(input, ac, av);
}
