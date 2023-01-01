/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_x_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:24 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/29 02:19:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

char	*spcf_x_lower(va_list *ptr)
{
	char	*dec;
	char	*hex;

	hex = 0;
	dec = ft_itoa_long(va_arg(*ptr, unsigned int));
	if (dec)
	{
		hex = ft_convert_base_ul(dec, "0123456789", "0123456789abcdef");
		free(dec);
	}
	return (hex);
}
