/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:26 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 09:47:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*spcf_u(va_list *ptr)
{
	return (ft_lstnew(ft_itoa_long(va_arg(*ptr, unsigned int))));
}
