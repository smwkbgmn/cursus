/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:53:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/24 04:43:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

char	*spcf_c(va_list *ptr)
{
	char	*c_str;

	c_str = malloc(2);
	if (c_str)
	{
		*c_str = (char)va_arg(*ptr, int);
		*(c_str + 1) = 0;
	}
	return (c_str);
}
