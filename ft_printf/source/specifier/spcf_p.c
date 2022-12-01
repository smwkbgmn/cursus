/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/02 02:20:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include "libft.h"

size_t	spcf_p(va_list *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(*ptr, void *);
	return (write_address(addr));
}
