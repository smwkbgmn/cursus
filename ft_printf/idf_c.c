/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idf_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:53:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/25 13:19:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	idf_c(va_list ptr)
{
	char	letter;

	letter = va_arg(ptr, int);
	write(1, &letter, 1);
}