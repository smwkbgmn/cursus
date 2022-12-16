/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_x_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:21 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/16 19:54:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	spcf_x_upper(va_list *ptr)
{
	char	*dec;
	char	*hex;

	dec = ft_itoa(va_arg(*ptr, unsigned int));
	if (!dec)
		return (0);
	hex = ft_convert_base(dec, "0123456789", "0123456789ABCDEF");
	free(dec);
	return (hex);
}
