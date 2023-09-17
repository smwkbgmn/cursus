/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:05:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/17 13:19:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	builtins_pwd(void)
{
	char	*path_curnt_dir;

	path_curnt_dir = getenv("PWD");
	if (path_curnt_dir)
		write(STDIN_FILENO, path_curnt_dir, )
}

void	ft_putstr(char *str)
{
	if (str)
	{
		if (*str)
		{
			write(STDIN_FILENO, str, 1);
			
		
}
