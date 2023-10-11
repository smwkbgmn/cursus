/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:05:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:16:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "builtin.h"

int	main(void)
{
	static char	*buf;

	buf = getcwd(buf, 0);
	if (!buf)
		exit_error("getcwd");
	printf("%s\n", buf);
	free(buf);
	return (EXIT_SUCCESS);
}
