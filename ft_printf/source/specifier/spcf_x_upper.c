/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_x_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:21 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/24 04:56:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

char	*spcf_x_upper(va_list *ptr)
{
	char	*dec;
	char	*hex;

	hex = 0;
	dec = ft_itoa(va_arg(*ptr, unsigned int));
	if (dec)
	{
		hex = ft_convert_base(dec, "0123456789", "0123456789ABCDEF");
		free(dec);
	}
	return (hex);
}
