/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_x_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:24 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/17 22:22:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*spcf_x_lower(va_list *ptr)
{
	char	*dec;
	char	*hex;

	dec = ft_itoa(va_arg(*ptr, unsigned int));
	if (!dec)
		return (0);
	hex = ft_convert_base(dec, "0123456789", "0123456789abcdef");
	free(dec);
	return (hex);
}
