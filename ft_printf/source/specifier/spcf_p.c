/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/16 19:54:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*spcf_p(va_list *ptr)
{
	char	*dec;
	char	*hex;
	char	*address;

	dec = ft_itoa(va_arg(*ptr, unsigned long));
	if (!dec)
		return (0);
	hex = ft_convert_base(dec, "0123456789", "0123456789abcdef");
	if (!hex)
		return (0);
	address = ft_strjoin("0x", hex);
	free(dec);
	free(hex);
	return (address);
}
