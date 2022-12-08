/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/08 18:11:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	spcf_p(va_list *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(*ptr, void *);
	return (write_address(addr));
}
