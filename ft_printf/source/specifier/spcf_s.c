/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/15 14:41:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	spcf_s(va_list *ptr)
{
	char	*str;

	str = va_arg(*ptr, char *);
	if (!str)
	{
		str = malloc(7);
		ft_strlcpy(str, "(null)", 7);
		return (str);
	}
	else
		return (str);
}
