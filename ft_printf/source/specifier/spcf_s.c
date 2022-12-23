/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/20 21:12:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*spcf_s(va_list *ptr)
{
	char	*str;

	str = va_arg(*ptr, char *);
	if (str)
		return (ft_strdup(str));
	else
		return (ft_strdup("(null)"));
}
