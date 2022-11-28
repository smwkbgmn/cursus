/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idf_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/29 01:39:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	idf_s(va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char *);
	ft_putstr_fd(str, 1);
}
